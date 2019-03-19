/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:58:32 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/19 14:17:01 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	draw_ant(char **ant, t_point p, t_mlx mlx)
{
	char	**temp;
	int		i;

	i = 0;
	while (ant[i])
	{
		temp = ft_strsplit(ant[i], ' ');
		pixel_put(mlx, p.x + ft_atoi(temp[0]),
				p.y + ft_atoi(temp[1]), ft_3pnt(128, 128, 128));
		ft_arrstrdel(temp);
		i++;
	}
}

void	draw_links(t_list *room, t_mlx mlx)
{
	t_list		*link;
	t_3point	clr;
	t_point		temp;
	t_point		link_pt;

	while (room)
	{
		ft_pntset(&temp, get_room(room)->x, get_room(room)->y);
		link = get_room(room)->link_list;
		while (link)
		{
			ft_pntset(&link_pt, get_room(link)->x, get_room(link)->y);
			clr = get_link_color(get_room(link), get_room(room));
			draw_wide_line(temp, link_pt, clr, mlx);
			link = link->next;
		}
		room = room->next;
	}
}

void	draw_ant_names(t_all *all)
{
	t_list	*list;
	t_room	*room;
	t_mlx	mlx;

	mlx = all->mlx;
	list = all->room;
	while (list)
	{
		room = get_room(list);
		if (room != all->start && room != all->end && room->ant_name)
			mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, room->x,
			room->y, 0xFFFFFFFF, room->ant_name);
		list = list->next;
	}
}

void	draw_names(t_all *all, int i)
{
	t_list	*list;
	t_room	*room;
	t_mlx	mlx;

	mlx = all->mlx;
	list = all->room;
	while (list)
	{
		room = get_room(list);
		mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, room->x - 50,
			room->y - 50, 0xFFFFFFFF, room->name);
		list = list->next;
	}
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 100, 100, 0xFFFFFFFF, "turn");
	mlx_putnbr(all->mlx, ft_pnt(150, 100), 0xFFFFFFFF, i);
	mlx_putnbr(all->mlx, ft_pnt(all->start->x - 20, all->start->y - 20),
			0xFFFFFFFF, all->start_count);
	mlx_putnbr(all->mlx, ft_pnt(all->end->x - 20, all->end->y - 20),
			0xFFFFFFFF, all->end_count);
	draw_ant_names(all);
}

void	draw_farm(t_list *room, int r, t_mlx mlx, char **ant)
{
	t_point		temp;
	t_list		*link;
	t_3point	clr;

	draw_links(room, mlx);
	while (room)
	{
		ft_pntset(&temp, get_room(room)->x, get_room(room)->y);
		clr = get_color(get_room(room));
		brez_circle(mlx, r, temp, clr);
		if (get_room(room)->is_empty == 0)
			draw_ant(ant, temp, mlx);
		link = get_room(room)->link_list;
		room = room->next;
	}
}
