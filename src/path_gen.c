/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 11:22:46 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/10 16:57:00 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_queue	*add_first_room(t_farm *farm, int *is_first_call)
{
	t_queue *path_qu;
	t_path	*path;
	t_list	*link;
	int		path_id;

	path_qu = queue_new();
	if (path_qu == NULL)
		error_handle(E_NOMEM);
	link = farm->start->link_list;
	path_id = 0;
	while (link)
	{
		path = path_new(20, path_id);
		path_add(path, farm->start);
		path_add(path, (t_room *)link->content);
		farm->start->is_visited[path_id] = 1;
		((t_room *)link->content)->is_visited[path_id] = 1;
		queue_put(path_qu, path);
		path_id++;
		link = link->next;
	}
	*is_first_call = -1;
	return (path_qu);
}

static int		check_path_loop(t_path *path, t_room *room)
{
	if (room->is_visited[path->id])
		return (-1);
	if (room->type == R_END)
		return (0);
	room->is_visited[path->id] = 1;
	return (0);
}

static t_path	*add_new_links(t_path *path, t_queue *path_qu)
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

void			path_free(void	*content)
{
	t_path	*path;

	path = (t_path *)content;
	free(path->ar);
	free(path);
}

t_path			*path_getnew(t_farm *farm)
{
	static int		is_first_call;
	static t_queue	*path_qu;
	t_path			*path;
	t_path			*result;

	if (farm == NULL)
	{
		queue_free(&path_qu, path_free);
		return (NULL);
	}
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
