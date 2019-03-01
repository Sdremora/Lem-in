
#include "lem_in.h"

int			resolve_check(t_resolve *resolve, t_path *add_path)
{
	int	i;
	int	n;
	int	k;
	t_path	*cur_path;
	t_room	*room;

	i = 0;
	while (i < resolve->cur_flow)
	{
		cur_path = resolve->path_ar[i];
		n = 1;
		while(n < cur_path->size - 1)
		{
			room = cur_path->ar[n];
			k = 1;
			while (k < add_path->size)
			{
				if (room == add_path->ar[k])
					return (0);
				k++;
			}
			n++;
		}
		i++;
	}
	return (1);
}

void		resolve_clean(t_resolve	*resolve)
{
	if (resolve)
	{
		free(resolve->path_ar);
		free(resolve);
	}
}

/*
t_resolve	*resolve_get_copy(t_resolve *resolve)
{
	t_resolve	*resolve_copy;
	int			i;

	resolve_copy = resolve_ini(resolve->flow_count);
	i = 0;
	while (i < resolve->cur_flow)
	{
		resolve_copy->path_ar[i] = resolve->path_ar[i];
		i++;
	}
	resolve_copy->cur_flow = resolve->cur_flow;
	resolve_copy->flow_count = resolve->flow_count;
	resolve_copy->move_count = resolve->move_count;
	return (resolve_copy);
}
*/

t_resolve	*resolve_ini(int flow_count)
{
	t_resolve	*resolve;

	if (!(resolve = (t_resolve *)malloc(sizeof(t_resolve))) ||\
		!(resolve->path_ar = (t_path **)ft_memalloc(sizeof(t_path *) * flow_count)))
		error_handle(E_NOMEM, E_NOMEM_STR);
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

	resolve = resolve_ini(flow);
	while (resolve->cur_flow < resolve->flow_count)
	{
		if (path_lst == NULL)
		{
			resolve_clean(resolve);
			return (NULL);
		}
		if (resolve_check(resolve, (t_path *)path_lst->content))
			resolve_path_add(resolve, (t_path *)path_lst->content);
		path_lst = path_lst->next;
	}
	return (resolve);
}

t_resolve	*get_resolve(t_farm *farm, t_resolve *last_resolve, int flow)
{
	static t_list	*path_lst;
	t_path			*path;
	t_resolve		*resolve;
	t_resolve		*save_resolve;
	int				l;
	int				max_size;

	resolve = NULL;
	save_resolve = NULL;
	max_size = -1;
	while ((path = path_getnew(farm)) != NULL)
	{
		path_to_lst(&path_lst, path);
		if (max_size != -1 && path->size > max_size)
			break ;
		resolve = resolve_builder(path_lst, flow);
		if (resolve)
		{
			if (flow <= 2)
				break;
			l = resolve->move_count - last_resolve->move_count - 1;
			if (l <= path->size)
				break;
			else
			{
				if (save_resolve == NULL)
				{
					save_resolve = resolve;
					max_size = l;
				}
				else
				{
					if (resolve->move_count < save_resolve->move_count)
					{
						resolve_clean(save_resolve);
						save_resolve = resolve;
					}
				}
			}
		}
	}
	if (resolve == NULL && save_resolve != NULL)
		resolve = save_resolve;
	return (resolve);
}

void	resolve_gen(t_farm *farm, t_list **resolve_lst, int max_step)
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
		resolve = get_resolve(farm, last_resolve, i);
		if (!resolve)
			break;
		last_resolve = resolve;
		node = ft_lstput(resolve, sizeof(t_resolve));
		if (node == NULL)
			error_handle(E_NOMEM, E_NOMEM_STR);
		ft_lstadd(resolve_lst, node);
		i++;
	}
}

void	print_eval(t_list	*resolve_lst)
{
	t_resolve	*resolve;
	t_path		*path;
	t_room		*room;
	int			i;
	int			k;

	ft_putstr("\n");
	while (resolve_lst)
	{
		ft_putstr("\nnext resolve:\n");
		resolve = (t_resolve *)resolve_lst->content;
		i = 0;
		while (i < resolve->flow_count)
		{
			path = resolve->path_ar[i];
			k = 0;
			while (k < path->size)
			{
				room = path->ar[k];
				ft_putstr(room->name);
				ft_putstr("\t");
				k++;
			}
			ft_putstr("\n");
			i++;
		}
		resolve_lst = resolve_lst->next;
	}
	ft_putstr("\n\n");
}

t_list *way_finder(t_farm *farm)
{
	t_list	*cur_rooms_list;
	t_list	*path_lst;
	t_list	*resolve_lst;
	int		max_step;

	farm->start->step = 0;
	cur_rooms_list = ft_lstput(farm->start, sizeof(t_room));
	if (!cur_rooms_list)
		error_handle(E_NOMEM, E_NOMEM_STR);
	max_step = marker(cur_rooms_list, 0);
	if (farm->end->pre_list == NULL)
		error_handle(E_NOPATH, E_NOPATH_STR);
	resolve_gen(farm, &resolve_lst, max_step);
	print_eval(resolve_lst);
	return (resolve_lst);
}
