
#include "lem_in.h"


int		resolve_isbest(t_state *state)
{
	int			cur_flow;
	t_resolve	*resolve;
	t_resolve	*prev_resolve;
	int			max_size;
	t_path		*path;

	cur_flow = state->cur_flow;
	if (state->res_ar[cur_flow] == NULL)
		return (0);
	if (cur_flow < 2)
		return (1);
	resolve = (t_resolve *)state->res_ar[cur_flow]->content;
	prev_resolve = (t_resolve *)state->res_ar[cur_flow - 1]->content;
	path = ((t_resolve *)state->last_one->content)->path_ar[0];
	max_size = resolve->move_count - prev_resolve->move_count;
	if (path->size < max_size)
		return (0);
	return (1);
}

int		path_check(t_path *path1, t_path *path2)
{
	t_room	*room;
	int		i;
	int		n;

	i = 1;
	while (i < path1->size - 1)
	{
		room = path1->ar[i];
		n = 1;
		while (n < path2->size - 1)
		{
			if (room == path2->ar[n])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

int		resolve_check(t_resolve *resolve, t_path *path)
{
	int i;
	t_path	*cur_path;

	i = 0;
	while (i < resolve->flow_count)
	{
		cur_path = resolve->path_ar[i];
		if (!path_check(cur_path, path))
			return (0);
		i++;
	}
	return (1);
}

void	resolve_to_state(t_state *state, t_resolve *resolve, int flow)
{
	t_list	*node;
	t_list	*temp;

	node = ft_lstput(resolve, resolve->move_count);
	if (!node)
		error_handle(E_NOMEM);
	if (state->res_ar[flow] == NULL)
		state->res_ar[flow] = node;
	else
	{
		temp = state->res_ar[flow];
		if (temp->content_size > node->content_size)
		{
			state->res_ar[flow] = node;
			node->next = temp;
		}
		else
		{
			node->next = temp->next;
			temp->next = node;
		}
	}
}

void	resolve_merge(t_state *state, t_resolve *resolve, t_path *path, int flow)
{
	t_resolve	*new_res;
	int			i;

	if (flow > state->max_flow)
		state->max_flow = flow;
	new_res = resolve_ini(flow + 1);
	i = 0;
	while (i < resolve->flow_count)
	{
		new_res->path_ar[i] = resolve->path_ar[i];
		i++;
	}
	new_res->path_ar[i] = path;
	new_res->move_count = resolve->move_count + path->size;
	resolve_to_state(state, new_res, flow);
}

void	resolve_addone(t_state *state, t_path *path)
{
	t_resolve	*new_res;
	t_list		*node;
	t_list		*temp;

	new_res = resolve_ini(1);
	new_res->path_ar[0] = path;
	new_res->move_count = path->size;
	node = ft_lstput(new_res, path->size);
	if (!node)
		error_handle(E_NOMEM);
	if (state->res_ar[0] == NULL)
	{
		state->res_ar[0] = node;
		state->last_one = node;
	}
	else
	{
		temp = state->last_one;
		state->last_one = node;
		temp->next = node;
	}
}

void	resolve_mixer(t_state *state, t_path *path)
{
	int			flow;
	t_list		*res_node;
	t_resolve	*resolve;

	flow = state->max_flow;
	while (flow >= 0)
	{
		res_node = state->res_ar[flow];
		while (res_node)
		{
			resolve = (t_resolve *)res_node->content;
			if (resolve_check(resolve, path))
				resolve_merge(state, resolve, path, flow + 1);
			res_node = res_node->next;
		}
		flow--;
	}
	resolve_addone(state, path);
}

void	state_fill(t_state *state, t_farm *farm)
{
	t_path	*path;

	while (state->cur_flow < state->target_flow)
	{
		if (resolve_isbest(state))
		{
			state->cur_flow++;
			continue;
		}
		path = path_getnew(farm);
		if (!path)
			break ;
		resolve_mixer(state, path);
	}
}

void	print_ones(t_state *state)
{
	t_list	*node;
	t_path	*path;
	int 	i;

	node = state->res_ar[0];
	ft_putstr("<==== Начало ====>\n");
	while (node)
	{
		path = ((t_resolve *)node->content)->path_ar[0];
		i = path->size;
		while (i > 0)
		{
			i--;
			ft_putstr(path->ar[i]->name);
			ft_putstr(" ");
		}
		ft_putstr("\n");
		node = node->next;
	}
	ft_putstr("<==== Конец ====>\n");
}

t_list	*resolve_make(t_farm *farm)
{
	t_list	*res_lst;
	t_state	*state;
	t_resolve	*resolve;
	t_list		*node;
	int 	i;

	res_lst = NULL;
	state = state_ini(farm);
	state_fill(state, farm);
	print_ones(state);
	i = 0;
	while (i < state->cur_flow)
	{
		resolve = (t_resolve *)state->res_ar[i]->content;
		node = ft_lstput(resolve, sizeof(t_resolve));
		if (!node)
			error_handle(E_NOMEM);
		ft_lstadd(&res_lst, node);
		i++;
	}
	return (res_lst);
}