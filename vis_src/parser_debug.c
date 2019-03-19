/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:05:34 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/14 18:30:11 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_printer(t_room *room)
{
	t_list *lst;

	ft_putendl(room->name);
	lst = room->link_list;
	ft_putnbr(ft_lstlen(lst));
	ft_putstr(" ");
	while (lst)
	{
		ft_putstr(((t_room*)lst->content)->name);
		ft_putstr(" ");
		lst = lst->next;
	}
	ft_putendl("");
	ft_putstr("\n");
}

void	farm_printer(t_farm *res)
{
	t_list *lst;

	lst = res->room;
	while (lst)
	{
		room_printer(lst->content);
		lst = lst->next;
	}
}

void	end_start_conn_printer(t_farm *res)
{
	room_printer(res->start);
	room_printer(res->end);
}

void	rooms_to_links(t_list *room1_lst, t_list *room2_lst)
{
	t_list	*node;

	node = ft_lstput(room1_lst->content, room1_lst->content_size);
	if (node == NULL)
		error_handle(E_NOMEM);
	ft_lstadd(&((t_room *)room2_lst->content)->link_list, node);
	node = ft_lstput(room2_lst->content, room2_lst->content_size);
	if (node == NULL)
		error_handle(E_NOMEM);
	ft_lstadd(&((t_room *)room1_lst->content)->link_list, node);
}
