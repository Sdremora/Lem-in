/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:29:15 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/06 16:09:12 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*path_finder(t_farm *farm, t_list **path_lst)
{
	t_list	*resolve_lst;

	resolve_lst = resolve_make(farm);
	return (resolve_lst);
}
