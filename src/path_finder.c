
#include "lem_in.h"

int			resolve_check(t_resolve *resolve, t_path *add_path)
{
	int		i;
	int		n;
	int		k;
	t_path	*cur_path;
	t_room	*room;

	i = 0;
	while (i < resolve->cur_flow)
	{
		cur_path = resolve->path_ar[i];
		n = 1;
		while (n < cur_path->size - 1)
		{
			room = cur_path->ar[n];
			k = 1;
			while (k < add_path->size)
			{
				if (room == add_path->ar[k++])
					return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}

void		resolve_clean(t_resolve *resolve)
{
	if (resolve)
	{
		free(resolve->path_ar);
		free(resolve);
	}
}

t_resolve	*resolve_ini(int flow_count)
{
	t_resolve	*resolve;

	if (!(resolve = (t_resolve *)malloc(sizeof(t_resolve))) ||\
		!(resolve->path_ar =\
		(t_path **)ft_memalloc(sizeof(t_path *) * flow_count)))
		error_handle(E_NOMEM);
	resolve->flow_count = flow_count;
	resolve->move_count = 0;
	resolve->cur_flow = 0;
	return (resolve);
}

int		get_flow(t_farm *farm)
{
	int	start_flow;
	int	end_flow;

	start_flow = ft_lstlen(farm->start->link_list);
	end_flow = ft_lstlen(farm->end->pre_list);
	return (start_flow < end_flow ? start_flow : end_flow);
}

void		resolve_path_add(t_resolve *resolve, t_path *path)
{
	resolve->path_ar[resolve->cur_flow] = path;
	resolve->cur_flow++;
	resolve->move_count += path->size;
}

t_resolve	*resolve_builder(t_list *path_lst, int flow)
{
	t_resolve	*resolve;
	t_list		*resolve_node;
	t_path		*path;

	resolve = resolve_ini(flow);
	while (resolve->cur_flow < resolve->flow_count)
	{
		if (path_lst == NULL)
		{
			resolve_clean(resolve);
			return (NULL);
		}
		path = (t_path *)path_lst->content;
		if (resolve_check(resolve, path))
			resolve_path_add(resolve, path);
		path_lst = path_lst->next;
	}
	return (resolve);
}

int			resolve_logic(t_resolve *resolve, t_resolve *last_resolve,\
			t_resolve **save_res, int *max_size)
{
	t_resolve *temp;

	if (*save_res == NULL)
	{
		*max_size = resolve->move_count - last_resolve->move_count - 1;
		if (resolve->path_ar[resolve->flow_count - 1]->size > *max_size)
			return (1);
		*save_res = resolve;
	}
	else if (resolve->move_count < (*save_res)->move_count)
	{
		temp = resolve;
		resolve = *save_res;
		*save_res = temp;
	}
	else
		resolve_clean(resolve);
	return (0);
}

t_resolve	*get_resolve(t_farm *farm, t_resolve *last_res,\
						int flow, t_list **path_lst)
{
	t_path			*path;
	t_resolve		*res;
	t_resolve		*save_res;
	int				max_size;

	res = NULL;
	save_res = NULL;
	max_size = 0;
	while ((path = path_getnew(farm)) != NULL)
	{
		res = NULL;
		path_to_lst(path_lst, path);
		if (save_res != NULL && path->size > max_size)
			break ;
		if ((res = resolve_builder(*path_lst, flow)) == NULL)
			continue ;
		if (flow <= 2 ||\
			resolve_logic(res, last_res, &save_res, &max_size) == 1)
			break ;
	}
	return (res != NULL) ? res : save_res;
}

void	resolve_gen(t_farm *farm, t_list **resolve_lst,\
					int max_step, t_list **path_lst)
{
	t_resolve	*resolve;
	t_resolve	*last_resolve;
	t_list		*node;
	int			max_flow;
	int			i;

	max_flow = get_flow(farm);
	*resolve_lst = NULL;
	last_resolve = NULL;
	i = 1;
	while (i <= max_flow)
	{
		resolve = get_resolve(farm, last_resolve, i, path_lst);
		if (!resolve)
			break ;
		last_resolve = resolve;
		node = ft_lstput(resolve, sizeof(t_resolve));
		if (node == NULL)
			error_handle(E_NOMEM);
		ft_lstadd(resolve_lst, node);
		i++;
	}
}

t_list	*path_finder(t_farm *farm, t_list **path_lst)
{
	t_list	*cur_rooms_list;
	t_list	*resolve_lst;
	int		max_step;

	*path_lst = NULL;
	farm->start->step = 0;
	cur_rooms_list = ft_lstput(farm->start, sizeof(t_room));
	if (!cur_rooms_list)
		error_handle(E_NOMEM);
	max_step = marker(cur_rooms_list, 0);
	if (farm->end->pre_list == NULL)
		error_handle(E_NOPATH);
	resolve_gen(farm, &resolve_lst, max_step, path_lst);
	return (resolve_lst);
}
