/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pntpls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:40:10 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/19 14:22:43 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	ft_pntplsy(t_point t, int i)
{
	t_point res;

	res.x = t.x;
	res.y = t.y + i;
	return (res);
}

t_point	ft_pntplsx(t_point t, int i)
{
	t_point res;

	res.x = t.x + i;
	res.y = t.y;
	return (res);
}

t_point	ft_pntpls(t_point p0, t_point p1)
{
	t_point res;

	res.x = p0.x + p1.x;
	res.y = p0.y + p1.y;
	return (res);
}
