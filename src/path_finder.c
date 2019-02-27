
#include "lem_in.h"

t_path	*path_ini(int path_size)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))) ||\
		!(path->ar = (t_room **)ft_memalloc(sizeof(t_room *) * path_size)))
		error_handle(E_NOMEM, E_NOMEM_STR);
	path->size = 0;
	path->max_size = path_size;
	return (path);
}

void	path_to_lst(t_list **lst, t_path *path)
{
	t_list	*path_node;

	path_node = ft_lstput(path, sizeof(t_path));
	if (!path_node)
		error_handle(E_NOMEM, E_NOMEM_STR);
	ft_lstadd(lst, path_node);
}

void	path_clear(t_path *path)
{
	free(path->ar);
	free(path);
}

t_path	*path_get_copy(t_path *path)
{
	t_path	*path_copy;
	int		i;

	path_copy = path_ini(path->max_size);
	i = 0;
	while (i < path->size)
	{
		path_copy->ar[i] = path->ar[i];
		i++;
	}
	path_copy->size = path->size;
	return (path_copy);
}

void	path_resize(t_path *path, int new_ar_size)
{
	t_room	**temp;
	int		i;

	if (new_ar_size <= path->max_size)
		return ;
	temp = (t_room **)ft_memalloc(sizeof(t_room *) * new_ar_size);
	if (!temp)
		error_handle(E_NOMEM, E_NOMEM_STR);
	i = 0;
	while (i < path->size)
	{
		temp[i] = path->ar[i];
		i++;
	}
	free(path->ar);
	path->ar = temp;
	path->max_size = new_ar_size;
}

int		path_builder(t_list **path_lst, t_path *path, t_room *room)
{
	t_room	**temp;
	int		i;

	if (path->size < 3 || path->ar[path->size - 2] != room)
	{
		if (path->size == path->max_size)
			path_resize(path, path->max_size * 2);
		path->ar[path->size] = room;
		path->size++;
		return (1);
	}
	else
		path_clear(path);
	return (0);
}

void	path_logic(t_list **path_lst, t_path *path, t_room *room)
{
	t_list	*node;
	t_list	*path_node;
	t_path	*path_copy;

	node = room->pre_list;
	if (node == NULL)
	{
		path_to_lst(path_lst, path);
		return ;
	}
	if (node->next == NULL)
	{
		if (path_builder(path_lst, path, (t_room *)node->content))
			path_logic(path_lst, path, (t_room *)node->content);
	}
	else
	{
		while (node->next)
		{
			path_copy = path_get_copy(path);
			if (path_builder(path_lst, path_copy, (t_room *)node->content))
				path_logic(path_lst, path_copy, (t_room *)node->content);
			node = node->next;
		}
		if (path_builder(path_lst, path, (t_room *)node->content))
			path_logic(path_lst, path, (t_room *)node->content);
	}
}

t_list	*path_combine(t_farm *farm, int	max_step)
{
	t_list	*path_lst;
	t_path	*path;

	path_lst = NULL;
	path = path_ini(max_step * 2);
	path->ar[0] = farm->end;
	path->size++;
	path_logic(&path_lst, path, farm->end);
	return (path_lst);
}

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

void		resolve_builder(t_list **temp_lst, t_resolve *resolve, t_list *path_lst)
{
	t_resolve	*resolve_copy;
	t_list		*resolve_node;

	while (resolve->cur_flow < resolve->flow_count)
	{
		if (path_lst == NULL)
		{
			resolve_clean(resolve);
			return ;
		}
		if (resolve_check(resolve, (t_path *)path_lst->content))
		{
			resolve_copy = resolve_get_copy(resolve);
			resolve_builder(temp_lst, resolve_copy, path_lst->next);
			resolve->path_ar[resolve->cur_flow] = (t_path *)path_lst->content;
			resolve->cur_flow++;
			resolve->move_count += ((t_path *)path_lst->content)->size;
		}
		path_lst = path_lst->next;
	}
	resolve_node = ft_lstput(resolve, sizeof(t_resolve));
	if (resolve_node == NULL)
		error_handle(E_NOMEM, E_NOMEM_STR);
	ft_lstadd(temp_lst, resolve_node);
}

t_resolve	*resolve_eval(t_list *temp_lst)
{
	t_resolve	*min_resolve;
	t_resolve	*cur_resolve;
	t_resolve	*temp;
	t_list		*next_node;

	min_resolve = NULL;
	while(temp_lst)
	{
		next_node = temp_lst->next;
		cur_resolve = (t_resolve *)temp_lst->content;
		if (!min_resolve || cur_resolve->move_count < min_resolve->move_count)
		{
			temp = min_resolve;
			min_resolve = cur_resolve;
			cur_resolve = temp;
		}
		resolve_clean(cur_resolve);
		free(temp_lst);
		temp_lst = next_node;
	}
	return (min_resolve);
}

t_resolve	*get_resolve(t_list *path_lst, int flow)
{
	t_list		*path_node;
	t_list		*temp_lst;
	t_resolve	*resolve;

	temp_lst = NULL;
	while (path_lst)
	{
		resolve = resolve_ini(flow);
		resolve_builder(&temp_lst, resolve, path_lst);
		if (flow == 1)
			path_lst = NULL;
		else
			path_lst = path_lst->next;
	}
	resolve = resolve_eval(temp_lst);
	return (resolve);
}

void	path_lst_clear(t_list *path_lst)
{
	t_list	*next_node;

	while (path_lst)
	{
		next_node = path_lst->next;
		path_clear((t_path *)path_lst);
		free(path_lst);
		path_lst = next_node;
	}
}

void	make_eval(t_farm *farm, t_list **resolve_lst, t_list *path_lst)
{
	t_resolve	*resolve;
	t_list		*node;
	int			max_flow;
	int			i;

	i = ft_lstlen(farm->start->link_list);
	max_flow = ft_lstlen(farm->end->link_list);
	max_flow = i < max_flow ? i : max_flow;
	i = 1;
	while (i <= max_flow)
	{
		resolve = get_resolve(path_lst, i);
		if (resolve == NULL)
			break;
		else
		{
			node = ft_lstput(resolve, sizeof(t_resolve));
			if (node == NULL)
				error_handle(E_NOMEM, E_NOMEM_STR);
			ft_lstadd(resolve_lst, node);
		}
		i++;
	}
	//path_lst_clear(path_lst);
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
	path_lst = path_combine(farm, max_step);
	resolve_lst = NULL;
	make_eval(farm, &resolve_lst, path_lst);
	print_eval(resolve_lst);
	return (resolve_lst);
 }
