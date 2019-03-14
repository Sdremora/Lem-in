/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:54:07 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/14 18:45:11 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	plotLineLow(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	t_point	delta;
	int		yi;
	int		D;
	t_point	p;

	ft_pntset(&delta, p1.x - p0.x, p1.y - p0.y);
	yi = 1;
	if (delta.y < 0)
	{
		yi = -1;
		delta.y = -delta.y;
	}
	D = 2 * delta.y - delta.x;
	ft_pntset(&p, p0.x, p0.y);
	while (p.x < p1.x)
	{
		pixel_put(mlx, p.x, p.y, clr);
		if (D > 0)
		{
			p.y += yi;
			D -= 2 * delta.x;
		}
		D += 2 * delta.y;
		p.x++;
	}
}

void	plotLineHigh(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	t_point delta;
	int     xi;
	int     D;
	t_point p;

	ft_pntset(&delta, p1.x - p0.x, p1.y - p0.y);
	xi = 1;
	if (delta.x < 0)
	{
		xi = -1;
		delta.x = -delta.x;
	}
	D = 2 * delta.x - delta.y;
	ft_pntset(&p, p0.x, p0.y);
	while (p.y < p1.y)
	{
		pixel_put(mlx, p.x, p.y, clr);
		if (D > 0)
		{
			p.x += xi;
			D -= 2 * delta.y;
		}
		D += 2 * delta.x;
		p.y++;
	}
}

void	plotLine(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	if (ft_abs(p1.y - p0.y) < ft_abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			plotLineLow(p1, p0, clr, mlx);
		else
			plotLineLow(p0, p1, clr, mlx);
	}
	else
	{
		if (p0.y > p1.y)
			plotLineHigh(p1, p0, clr, mlx);
		else
			plotLineHigh(p0, p1, clr, mlx);
	}			
}
