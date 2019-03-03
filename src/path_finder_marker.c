/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_marker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 11:58:39 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/03 12:03:51 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	2 -> content exist in lst and have different step
**	1 -> content exist in lst and have same step
**	0 -> not exist
*/

static int	check_exist(t_list *lst, t_room *found_room, int step)
{
	while (lst)
	{
		if (lst->content == found_room)
		{
			if (((t_room *)lst->content)->step == step)
				return (1);
			return (2);
		}
		lst = lst->next;
	}
	return (0);
}

static int	add_mark(t_room *next_room, t_room *room, int step)
{
	t_list	*node;
	int		status;

	status = check_exist(room->pre_list, next_room, room->step);
	if (status == 2)
		return (0);
	node = ft_lstput(room, sizeof(t_room));
	if (!node)
		error_handle(E_NOMEM);
	ft_lstadd(&next_room->pre_list, node);
	if ((next_room->pre_list->next != NULL) ||\
		(status != 0) ||\
		(next_room->type == R_END))
		return (0);
	return (1);
}

static void	add_link(t_list **next_room_lst, t_room *room, int step)
{
	t_list	*link_lst;
	t_list	*new_node;
	t_room	*next_room;

	link_lst = room->link_list;
	while (link_lst != NULL)
	{
		next_room = (t_room *)link_lst->content;
		if (add_mark(next_room, room, step))
		{
			next_room->step = step;
			new_node = ft_lstput(next_room, sizeof(t_room));
			if (new_node == NULL)
				error_handle(E_NOMEM);
			ft_lstadd(next_room_lst, new_node);
		}
		link_lst = link_lst->next;
	}
}

/*
**	Mark directions in all nodes.
*/

int			marker(t_list *room_lst, int step)
{
	t_list	*next_room_lst;
	t_list	*temp;

	if (!room_lst)
		return (step);
	step++;
	next_room_lst = NULL;
	while (room_lst)
	{
		add_link(&next_room_lst, (t_room *)room_lst->content, step);
		temp = room_lst;
		room_lst = room_lst->next;
		free(temp);
	}
	return (marker(next_room_lst, step));
}
