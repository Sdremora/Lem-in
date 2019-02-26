
#include "lem_in.h"
#include "libft.h"

// /*
// **	2 -> content exist in lst and have different step
// **	1 -> content exist in lst and have same step
// **	0 -> not exist
// */

// int		check_exist(t_list *lst, t_room *found_room, int step)
// {
// 	while (lst)
// 	{
// 		if (lst->content == found_room)
// 		{
// 			if (((t_room *)lst->content)->step == step)
// 				return (1);
// 			return (2);
// 		}
// 		lst = lst->next;
// 	}
// 	return (0);
// }

// #define R_END 1

// int		add_mark(t_room *next_room, t_room *room, int step)
// {
//  	t_list	*node;
// 	int		status;

// 	status = check_exist(room->pre_list, next_room, step);
// 	if (status == 2)
// 		return (0);
//  	node = ft_lstput(room, sizeof(t_room));
//  	if (!node)
//  		error_handle(E_NOMEM, E_NOMEM_STR);
//  	ft_lstadd(&next_room->pre_list, node);
// 	if (next_room->pre_list->next != NULL ||\
// 		status != 0 ||\
// 		next_room->type == R_END)
// 		return (0);
// 	return (1);
// }

//  t_list		*add_link(t_list **next_room_lst, t_room *room, int step) // room = 3
//  {
//  	t_list	*link_lst;
//  	t_list	*new_node;
//  	t_room	*next_room;

//  	link_lst = room->link_list;
//  	while (link_lst != NULL)
//  	{
//  		next_room = (t_room *)link_lst->content; // next_room = 1
//  		if (add_mark(next_room, room, step))
// 		{
// 			next_room->step = step;
// 			new_node = ft_lstput(next_room, sizeof(t_room));
// 			if (new_node == NULL)
// 				error_handle(E_NOMEM, E_NOMEM_STR);
// 			ft_lstadd(next_room_lst, new_node);
// 		}
//  		link_lst = link_lst->next;
//  	}
//  }

//  int		marker(t_list *room_lst, int step)
//  {
//  	t_list	*next_room_lst;

//  	if (!room_lst)
//  		return (step);
// 	step++;
//  	while (room_lst)
//  	{
//  		add_link(&next_room_lst, (t_room *)room_lst->content, step);
//  		room_lst = room_lst->next;
//  	}
//  	return (marker(next_room_lst, step));
//  }

// t_path	*path_ini(int path_size)
// {
// 	t_path	*path;

// 	if (!(path = (t_path *)malloc(sizeof(t_path))) ||\
// 		!(path->ar = (t_room **)ft_memalloc(sizeof(t_room *) * path_size)))
// 		error_handle(E_NOMEM, E_NOMEM_STR);
// 	path->size = 0;
// 	path->max_size = path_size;
// 	return (path);
// }

// void	path_to_lst(t_list **lst, t_path *path)
// {
// 	t_list	*path_node;

// 	path_node = ft_lstput(path, sizeof(t_path));
// 	if (!path_node)
// 		error_handle(E_NOMEM, E_NOMEM_STR);
// 	ft_lstadd(lst, path_node);
// }

// void	path_clear(t_path *path)
// {
// 	free(path->ar);
// 	free(path);
// }

// t_path	*path_get_copy(t_path *path)
// {
// 	t_path	*path_copy;
// 	int		i;

// 	path_copy = path_ini(path->max_size);
// 	i = 0;
// 	while (i < path->size)
// 	{
// 		path_copy->ar[i] = path->ar[i];
// 		i++;
// 	}
// 	path_copy->size = path->size;
// 	return (path_copy);
// }

// void	path_builder(t_list **path_lst, t_path *path, t_room *room)
// {
// 	if (path->size < 3 || path->ar[path->size - 2] != room)
// 	{
// 		path->ar[path->size] = room;
// 		path->size++;
// 		path_logic(path_lst, path, (t_room *)room->pre_list->content);
// 	}
// 	else
// 		path_clear(path);
// }

// void	path_logic(t_list **path_lst, t_path *path, t_room *room)
// {
// 	t_list	*node;
// 	t_list	*path_node;
// 	t_path	*path_copy;

// 	node = room->pre_list;
// 	if (node == NULL)
// 	{
// 		path_to_lst(path_lst, path);
// 		return ;
// 	}
// 	if (node->next == NULL)
// 		path_builder(path_lst, path, (t_room *)node->content);
// 	else
// 	{
// 		while (node->next)
// 		{
// 			path_copy = path_get_copy(path);
// 			path_builder(path_lst, path_copy, (t_room *)node->content);
// 			node = node->next;
// 		}
// 		path_builder(path_lst, path, (t_room *)node->content);
// 	}
// }

// t_list	*path_combine(t_farm *farm, int	max_step)
// {
// 	t_list	*path_lst;
// 	t_path	*path;

// 	path_lst = NULL;
// 	path = path_ini(max_step);
// 	path->ar[0] = farm->end;
// 	path->size++;
// 	path_logic(&path_lst, path, farm->end);
// 	return (path_lst);
// }

// t_resolve	*resolve_ini(int flow_count)
// {
// 	t_resolve	*resolve;

// 	if ((resolve = (t_resolve *)malloc(sizeof(t_resolve))) ||\
// 		(resolve->path_ar = (t_path **)ft_memalloc(sizeof(t_path *) * flow_count)))
// 		error_handle(E_NOMEM, E_NOMEM_STR);
// 	resolve->flow_count = flow_count;
// 	resolve->move_count = -1;
// 	return (resolve);
// }

// int			resolve_add(t_resolve *resolve, t_path *add_path)
// {

// }

// void		resolve_builder(t_resolve *resolve, t_path *path, int flow)
// {

// }

// t_resolve	*get_resolve(t_list *path_lst, int flow)
// {
// 	t_list		*path_node;
// 	t_list		*node;
// 	t_resolve	*resolve;
// 	int			i;

// 	while (path_lst)
// 	{
// 		resolve = resolve_ini(flow);
// 		node = path_node->next;
// 		i = 0;

// 		path_lst = path_lst->next;
// 	}

// 	return (resolve);
// }

// void	make_eval(t_farm *farm, t_list **resolve_lst, t_list *path_lst)
// {
// 	t_resolve	*resolve;
// 	t_list		*node;
// 	int			max_flow;
// 	int			i;

// 	i = ft_lstlen(farm->start->link_list);
// 	max_flow = ft_lstlen(farm->end->link_list);
// 	max_flow = i < max_flow ? i : max_flow;
// 	i = 1;
// 	while (i <= max_flow)
// 	{
// 		resolve = get_resolve(path_lst, i);
// 		if (resolve == NULL)
// 			break;
// 		else
// 		{
// 			node = ft_lstput(resolve, sizeof(t_resolve));
// 			if (node == NULL)
// 				error_handle(E_NOMEM, E_NOMEM_STR);
// 			ft_lstadd(resolve_lst, node);
// 		}
// 		i++;
// 	}
// }

//  t_list *way_finder(t_farm *farm)
//  {
//  	t_list	*cur_rooms_list;
// 	t_list	*path_lst;
// 	t_list	*resolve_lst;
// 	int		max_step;

// 	farm->room[0]->step = 0;
//  	cur_rooms_list = ft_lstput(farm->room[0], sizeof(t_room));
//  	if (!cur_rooms_list)
//  		error_handle(E_NOMEM, E_NOMEM_STR);
//  	max_step = marker(cur_rooms_list, 0);
// 	if (farm->end->pre_list == NULL)
// 		error_handle(E_NOPATH, E_NOPATH_STR);
// 	path_lst = path_combine(farm, max_step);
// 	resolve_lst = NULL;
// 	make_eval(farm, &resolve_lst, path_lst);
// 	return (resolve_lst);
//  }

t_list *way_finder(t_farm *farm)
{
	return (NULL);
}
