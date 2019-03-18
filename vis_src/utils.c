/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:47:55 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/18 17:53:15 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_end(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	init(t_mlx *mlx)
{
	mlx->bpp = 32;
	mlx->size_line = 4 * WD_X;
	mlx->endian = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WD_X, WD_Y, "Lem-in");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WD_X, WD_Y);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
}

void	pixel_put(t_mlx mlx, int x, int y, t_3point color)
{
	if (x > 0 && y > 0 && x < WD_X && y < WD_Y)
	{
		mlx.img_data[x * 4 + 4 * WD_X * y + 2] = color.x;
		mlx.img_data[x * 4 + 4 * WD_X * y + 1] = color.y;
		mlx.img_data[x * 4 + 4 * WD_X * y] = color.z;
	}
}

void	draw_inner_circle(t_mlx mlx, t_point c, t_point p, t_3point color)
{
	t_point p0;

	ft_pntset(&p0, c.x + p.x, c.y + p.y);
	while (p0.y >= c.y - p.y)
	{
		pixel_put(mlx, p0.x, p0.y, color);
		p0.y--;
	}
	ft_pntset(&p0, c.x - p.x, c.y + p.y);
	while (p0.y >= c.y - p.y)
	{
		pixel_put(mlx, p0.x, p0.y, color);
		p0.y--;
	}
}

void	brez_circle(t_mlx mlx, int r, t_point c, t_3point color)
{
	int		x;
	int		y;
	int		delta;
	int		error;

	x = 0;
	y = r;
	delta = 1 - 2 * r;
	error = 0;
	while (y >= 0)
	{
		draw_inner_circle(mlx, c, ft_pnt(x, y), color);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += 2 * ++x + 1;
			continue;
		}
		if ((delta > 0) && (error > 0))
		{
			delta -= 2 * --y + 1;
			continue;
		}
		delta += 2 * (++x - y--);
	}
}
