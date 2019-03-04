/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:17:57 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/04 10:51:14 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static void		path_build(t_list **result_lst, t_list **next_lst,\
							t_path *path, t_room *room)
{
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
