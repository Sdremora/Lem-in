/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:04:48 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/18 18:11:27 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_3point	get_color(t_room *room)
{
	if (room->type == R_DEF)
		return (ft_3pnt(128, 128, 128));
	else
		return (ft_3pnt(0, 0, 128));
}

t_3point	get_link_color(t_room *r1, t_room *r2)
{
	if (r1->type != R_DEF && r2->type != R_DEF)
		return (ft_3pnt(0, 0, 128));
	else
		return (ft_3pnt(128, 128, 128));
}
