/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:43:46 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/18 20:21:50 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H

# define GRAPHIC_H

# define WD_X 2560
# define WD_Y 1200
# include "mlx.h"

typedef struct		s_all
{
	t_mlx			mlx;
	char			*res;
	t_path			**path_ar;
	t_list			*room;
	char			**pic;
	t_ant			*ant;
	int				ant_count;
	t_room			*start;
	t_room			*end;
	int				start_count;
	int				end_count;
}					t_all;

typedef struct		s_dblpoint
{
	double			x;
	double			y;
}					t_dblpoint;

void				ft_dblpointset(t_dblpoint *p, double x, double y);
int					ft_end(void *param);
void				init(t_mlx *mlx);
void				brez_circle(t_mlx mlx, int r, t_point c, t_3point color);
void				pixel_put(t_mlx mlx, int x, int y, t_3point color);

void				plot_line(t_point p0, t_point p1, t_3point clr, t_mlx mlx);
void				mlx_putnbr(t_mlx mlx, t_point p, int color, int n);
void				draw_wide_line(t_point p0, t_point p1,
					t_3point clr, t_mlx mlx);

void				draw_file(char *name, t_point p, t_mlx mlx, t_3point clr);
void				ant_move(t_point p0, t_point p1, char **ant, t_mlx mlx);
char				**read_ant(char *fname);

t_ant				*solver_vis(t_list *resolve, int ant_count);

t_3point			get_color(t_room *room);
t_3point			get_link_color(t_room *r1, t_room *r2);

void				draw_ant(char **ant, t_point p, t_mlx mlx);
void				draw_links(t_list *room, t_mlx mlx);
void				draw_farm(t_list *room, int r, t_mlx mlx, char **ant);
void				draw_names(t_all *all, int i);

#endif
