
#include "lem_in.h"

t_path	*path_ini(int path_size)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))) ||\
		!(path->ar = (t_room **)ft_memalloc(sizeof(t_room *) * path_size)))
		error_handle(E_NOMEM);
	path->size = 0;
	path->max_size = path_size;
	return (path);
}

void	path_to_lst(t_list **lst, t_path *path)
{
	t_list	*path_node;

	path_node = ft_lstput(path, sizeof(t_path));
	if (!path_node)
		error_handle(E_NOMEM);
	ft_lstadd(lst, path_node);
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
		error_handle(E_NOMEM);
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

static t_list	*path_first_ini(t_farm *farm, int *is_first_call)
{
	t_list	*path_lst;
	t_path	*path;

	path_lst = NULL;
	path = path_ini(10);
	path->ar[0] = farm->end;
	path->size++;
	path_to_lst(&path_lst, path);
	*is_first_call = 1;
	return (path_lst);
}

static void		path_next_and_free(t_list **path_lst, t_list **next_lst)
{
	t_list	*temp;
	t_path	*path;

	temp = *path_lst;
	*path_lst = (*path_lst)->next;
	path = (t_path *)temp->content;
	free(path->ar);
	free(path);
	free(temp);
	if (!*path_lst && *next_lst)
	{
		*path_lst = *next_lst;
		*next_lst = NULL;
	}
}

void			path_add(t_list **lst, t_path *orig_path, t_room *add_room)
{
	t_path	*path_copy;

	path_copy = path_get_copy(orig_path);
	if (path_copy->size == path_copy->max_size)
		path_resize(path_copy, path_copy->max_size * 2);
	path_copy->ar[path_copy->size] = add_room;
	path_copy->size++;
	path_to_lst(lst, path_copy);
}

void			path_build(t_list **result_lst, t_list **next_lst,\
							t_path *path, t_room *room)
{
	t_path	*path_copy;
	int		i;

	i = 1;
	if (room->type == R_START)
		path_add(result_lst, path, room);
	else
	{
		while (i < path->size)
		{
			if (path->ar[i] == room)
				return ;
			i++;
		}
		path_add(next_lst, path, room);
	}
}

void	path_free(t_list *path_lst)
{
	t_list		*next_node;
	t_path		*path;

	while (path_lst)
	{
		next_node = path_lst->next;
		path = (t_path *)path_lst->content;
		free(path->ar);
		free(path);
		free(path_lst);
		path_lst = next_node;
	}
}

void			path_logic(t_list **res_lst, t_farm *farm)
{
	static int		is_first_call;
	static t_list	*path_lst;
	static t_list	*next_lst;
	t_list			*room_lst;
	t_path			*path;

	if (!res_lst)
	{
		path_free(path_lst);
		path_free(next_lst);
		return ;
	}
	if (!is_first_call)
		path_lst = path_first_ini(farm, &is_first_call);
	while (path_lst && !*res_lst)
	{
		path = (t_path *)path_lst->content;
		room_lst = (path->ar[path->size - 1])->pre_list;
		while (room_lst)
		{
			path_build(res_lst, &next_lst, path, (t_room *)room_lst->content);
			room_lst = room_lst->next;
		}
		path_next_and_free(&path_lst, &next_lst);
	}
}

t_path	*path_getmin(t_list **path_lst)
{
	t_path	*path;
	t_list	*temp;

	path = (t_path *)(*path_lst)->content;
	temp = *path_lst;
	*path_lst = (*path_lst)->next;
	free(temp);
	return (path);
}

t_path		*path_getnew(t_farm *farm)
{
	static t_list	*path_lst;
	t_list			*temp;
	t_path			*path;

	if (farm == NULL)
	{
		path_logic(NULL, NULL);
		return (NULL);
	}
	if (path_lst)
	{
		path = (t_path *)path_lst->content;
		temp = path_lst;
		path_lst = path_lst->next;
		free(temp);
	}
	else
	{
		path_logic(&path_lst, farm);
		if (!path_lst)
			return (NULL);
		path = path_getmin(&path_lst);
	}
	return (path);
}
