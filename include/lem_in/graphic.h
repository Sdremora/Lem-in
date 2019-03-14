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
void				plotLine(t_point p0, t_point p1, t_3point clr, t_mlx mlx);

#endif
