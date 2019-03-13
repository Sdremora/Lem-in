/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_deadend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:05:07 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/13 11:36:44 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	link_del(t_room *delroom, t_room *dst)
{
	t_list	*prev;
	t_list	*lst;
	t_list	*next;

	lst = dst->link_list;
	prev = 0;
	while (lst)
	{
		next = lst->next;
		if ((t_room*)lst->content == delroom)
		{
			if (!prev)
				dst->link_list = next;
			else
				prev->next = next;
			free(lst);
			break ;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
}

int		dead_list_remover(t_list *lst)
{
	t_room	*room;

	room = lst->content;
	if (room->link_list)
	{
		link_del(room, room->link_list->content);
		free(room->link_list);
	}
	free(room->name);
	free(room);
	free(lst);
	return (1);
}

int		deadend_remover_farm(t_farm *farm)
{
	t_list	*lst;
	t_list	*next;
	t_list	*prev;

	lst = farm->room;
	prev = 0;
	while (lst)
	{
		next = lst->next;
		if (ft_lstlen((get_room(lst)->link_list)) <= 1 &&
				lst->content != farm->end && lst->content != farm->start)
		{
			if (!prev)
				farm->room = next;
			else
				prev->next = next;
			return (dead_list_remover(lst));
		}
		else
		{
			prev = lst;
			lst = next;
		}
	}
	return (0);
}
