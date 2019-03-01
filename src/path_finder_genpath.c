
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

void	free_path_lst(t_list *path_lst)
{
	t_path	*path;

	path = (t_path *)path_lst->content;
	free(path->ar);
	free(path);
	free(path_lst);
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

static t_list	*path_first_ini(t_farm *farm, int *is_first_call)
{
	t_list	*path_lst;
	t_path	*path;

	path = path_ini(10);
	path->ar[0] = farm->end;
	path->size++;
	path_to_lst(&path_lst, path);
	*is_first_call = 1;
	return (path_lst);
}

static t_list	*path_next_and_free(t_list *lst)
{
	t_list	*temp;
	t_path	*path;

	temp = lst;
	lst = lst->next;
	path = (t_path *)temp->content;
	free(path->ar);
	free(path);
	free(temp);
	return (lst);
}

void			path_logic(t_list **result_lst, t_farm *farm)
{
	static			*is_first_call;
	static t_list	*path_lst;
	static t_list	*next_lst;
	t_list			*room_lst;
	t_path			*path;

	if (!is_first_call)
		path_lst = path_first_ini(farm, &is_first_call);
	while (path_lst && !result_lst)
	{
		path = (t_path *)path_lst->content;
		room_lst = (path->ar[path->size - 1])->pre_list;
		while (room_lst)
		{
			path_build(&result_lst, &next_lst, path, (t_room *)room_lst->content);
			room_lst = room_lst->next;
		}
		path_lst = next_and_free(path_lst);
		if (!path_lst && next_lst)
		{
			path_lst = next_lst;
			next_lst = NULL;
		}
	}
}

t_path *path_getnew(t_farm	*farm)
{
	static t_list	*path_lst;
	t_list			*temp;
	t_path			*path;

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
		path = get_path();
	}
	return (path);
}
