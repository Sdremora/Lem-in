/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:05:34 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/11 14:05:36 by hharvey          ###   ########.fr       */
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
