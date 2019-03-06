#include "lem_in.h"

t_queue	*add_first_room(t_farm *farm, int *is_first_call)
{
	t_queue *path_qu;
	t_path	*path;

	path_qu = queue_new();
	if (path_qu == NULL)
		error_handle(E_NOMEM);
	path = path_new(20);
	path_add(path, farm->start);
	queue_put(path_qu, path);
	*is_first_call = -1;
	return (path_qu);
}

int		check_path_loop(t_path *path, t_room *room)
{
	int i;

	i = path->size;
	while (i > 1)
	{
		i--;
		if (path->ar[i - 1] == room)
			return (-1);
	}
	if (room->type == R_START)
		return (-1);
	return (0);
}

t_path	*add_new_links(t_path *path, t_queue *path_qu)
{
	t_room	*room;
	t_path	*result;
	t_list	*links;
	t_path	*new_path;

	result = NULL;
	links = path->ar[path->size - 1]->link_list;
	while (links)
	{
		room = (t_room *)links->content;
		if (!check_path_loop(path, room))
		{
			new_path = path_copy(path);
			path_add(new_path, room);
			if (room->type == R_END)
				result = new_path;
			else
				queue_put(path_qu, new_path);
		}
		links = links->next;
	}
	return (result);
}

t_path	*path_getnew(t_farm	*farm)
{
	static int		is_first_call;
	static t_queue	*path_qu;
	t_path			*path;
	t_path			*result;

	if (!is_first_call)
		path_qu = add_first_room(farm, &is_first_call);
	result = NULL;
	while (!result)
	{
		path = (t_path *)queue_get(path_qu);
		if (path == NULL)
			return (NULL);
		result = add_new_links(path, path_qu);
		free(path->ar);
		free(path);
	}
	return (result);
}

int	lstlen(t_list *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
