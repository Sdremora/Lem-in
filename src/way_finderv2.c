/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_finderv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:22:16 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/24 13:35:46 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

// void		add_pre_room(t_room *room, t_room *pre_room)
// {
// 	t_list	*node;

// 	node = ft_lstput(pre_room, sizeof(*pre_room));
// 	if (!node)
// 		error_handle(E_NOMEM, E_NOMEM_STR);
// 	ft_lstadd(&room->pre_list, node);
// }

// t_list		*add_link(t_list **rooms, t_room *room)
// {
// 	t_list	*node;
// 	t_list	*new_node;
// 	t_room	*next_room;

// 	node = room->link_list;
// 	while (node != NULL)
// 	{
// 		next_room = (t_room *)node->content;
// 		add_pre_room(next_room, room);
// 		new_node = ft_lstput(room, sizeof(t_room));
// 		if (new_node == NULL)
// 			error_handle(E_NOMEM, E_NOMEM_STR);
// 		ft_lstadd(rooms, new_node);
// 		node = node->next;
// 	}
// }

// void		marker(t_list *cur_rooms_list)
// {
// 	t_list	*next_rooms;
// 	t_list	*cur_room;

// 	if (!cur_rooms_list)
// 		return ;
// 	cur_room = cur_rooms_list;
// 	while (cur_room)
// 	{
// 		add_link(&next_rooms, cur_room);

// 		cur_room = cur_room->next;
// 	}

// 	marker(next_rooms);
// }

// t_resolve *way_finder(t_farm *farm)
// {
// 	t_list	*cur_rooms_list;

// 	cur_rooms_list = ft_lstput(farm->room[0], sizeof(t_room));
// 	if (!cur_rooms_list)
// 		error_handle(E_NOMEM, E_NOMEM_STR);
// 	marker(cur_rooms_list);

// }

t_list *way_finder(t_farm *farm)
{
	t_resolve	*resolve;



}