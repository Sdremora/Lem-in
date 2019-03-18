/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:54:07 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/18 19:27:05 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	plot_line_low(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	t_point	delta;
	int		yi;
	int		d;
	t_point	p;

	ft_pntset(&delta, p1.x - p0.x, p1.y - p0.y);
	yi = 1;
	if (delta.y < 0)
	{
		yi = -1;
		delta.y = -delta.y;
	}
	d = 2 * delta.y - delta.x;
	ft_pntset(&p, p0.x, p0.y);
	while (p.x < p1.x)
	{
		pixel_put(mlx, p.x, p.y, clr);
		if (d > 0)
		{
			p.y += yi;
			d -= 2 * delta.x;
		}
		d += 2 * delta.y;
		p.x++;
	}
}

void	plot_line_high(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	t_point	delta;
	int		xi;
	int		d;
	t_point	p;

	ft_pntset(&delta, p1.x - p0.x, p1.y - p0.y);
	xi = 1;
	if (delta.x < 0)
	{
		xi = -1;
		delta.x = -delta.x;
	}
	d = 2 * delta.x - delta.y;
	ft_pntset(&p, p0.x, p0.y);
	while (p.y < p1.y)
	{
		pixel_put(mlx, p.x, p.y, clr);
		if (d > 0)
		{
			p.x += xi;
			d -= 2 * delta.y;
		}
		d += 2 * delta.x;
		p.y++;
	}
}

void	plot_line(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	if (ft_abs(p1.y - p0.y) < ft_abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			plot_line_low(p1, p0, clr, mlx);
		else
			plot_line_low(p0, p1, clr, mlx);
	}
	else
	{
		if (p0.y > p1.y)
			plot_line_high(p1, p0, clr, mlx);
		else
			plot_line_high(p0, p1, clr, mlx);
	}
}

void	draw_wide_line(t_point p0, t_point p1, t_3point clr, t_mlx mlx)
{
	int i;

	i = 0;
	while (i < 5)
	{
		plot_line(ft_pntplsx(p0, i), ft_pntplsx(p1, i), clr, mlx);
		plot_line(ft_pntplsx(p0, -i), ft_pntplsx(p1, -i), clr, mlx);
		plot_line(ft_pntplsy(p0, i), ft_pntplsy(p1, i), clr, mlx);
		plot_line(ft_pntplsy(p0, -i), ft_pntplsy(p1, -i), clr, mlx);
		i++;
	}
}

void	mlx_putnbr(t_mlx mlx, t_point p, int color, int n)
{
	char	*temp;

	temp = ft_itoa(n);
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, p.x, p.y, color, temp);
	free(temp);
}
