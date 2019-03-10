
#include "lem_in.h"

void	room_in_har(t_resolve *resolve, t_room *room)
{
	t_list	*node;
	t_list	*temp;
	int		index;

	if (room->hash == 0)
		room->hash = mafast_hash(room->name, ft_strlen(room->name));
	node = ft_lstput(room, room->hash);
	if (node == NULL)
		error_handle(E_NOMEM);
	index = room->hash % resolve->har_size;
	if (resolve->rooms_har[index] == NULL)
		resolve->rooms_har[index] = node;
	else
	{
		temp = resolve->rooms_har[index];
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

void	hash_fill(t_resolve	*resolve)
{
	int		i;
	int		n;
	t_path	*path;

	resolve->har_size = resolve->move_count * 1.5;
	resolve->rooms_har = (t_list **)ft_memalloc(sizeof(t_list *) * resolve->har_size);
	if (resolve->rooms_har == NULL)
		error_handle(E_NOMEM);
	i = 0;
	while (i < resolve->flow_count)
	{
		path = resolve->path_ar[i];
		n = 0;
		while (n < path->size)
		{
			room_in_har(resolve, path->ar[n]);
			n++;
		}
		i++;
	}
}

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

int		resolve_check(t_resolve *resolve, t_path *path)
{
	int		i;
	int		n;
	t_list	*node;
	t_room	*room;

	i = 1;
	while (i < path->size - 1)
	{
		room = path->ar[i];
		if (room->hash != 0)
		{
			n = room->hash % resolve->har_size;
			node = resolve->rooms_har[n];
			while (node)
			{
				if (node->content_size == room->hash)
					return (0);
				node = node->next;
			}
		}
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
	hash_fill(new_res);
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
	hash_fill(new_res);
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
	state->res_count++;
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
			{
				resolve_merge(state, resolve, path, flow + 1);
				state->res_count++;
			}
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
			if (state->res_count > 150000)
				break ;
			continue;
		}
		path = path_getnew(farm);
		if (!path)
			break ;
		resolve_mixer(state, path);
	}
}

// void	state_free(t_state	*state)
// {
// 	t_list	*node;
// 	int		i;
// 	int		n;

// 	i = 0;
// 	while (i < state->max_flow)
// 	{
// 		node = state->res_ar[i];
// 		n =

// 	}
// }

t_list	*resolve_finder(t_farm *farm, t_state *state)
{
	int 		i;
	t_list		*result_lst;
	t_list		*node;
	t_resolve	*resolve;

	result_lst = NULL;
	state_fill(state, farm);
	i = 0;
	while (i < state->cur_flow)
	{
		resolve = (t_resolve *)state->res_ar[i]->content;
		node = ft_lstput(resolve, sizeof(t_resolve));
		if (!node)
			error_handle(E_NOMEM);
		ft_lstadd(&result_lst, node);
		i++;
	}
	// state_free(state);
	return (result_lst);
}
