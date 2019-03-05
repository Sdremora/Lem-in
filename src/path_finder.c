/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:29:15 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/05 12:45:36 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*path_finder(t_farm *farm, t_list **path_lst)
{
	t_list	*cur_rooms_list;
	t_list	*resolve_lst;

	*path_lst = NULL;
	farm->start->step = 0;
	cur_rooms_list = ft_lstput(farm->start, sizeof(t_room));
	if (!cur_rooms_list)
		error_handle(E_NOMEM);
	marker(cur_rooms_list, 0);
	if (farm->end->pre_list == NULL)
		error_handle(E_NOPATH);
	//resolve_gen(farm, &resolve_lst, path_lst);
	resolve_lst = resolve_make(farm);
	return (resolve_lst);
}
