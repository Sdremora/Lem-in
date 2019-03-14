
#include "lem_in.h"

int		deal_key(int key, t_all *all)
{
	if (key == 53)
		exit(1);
	return (0);

}

void	draw_farm(t_list *room, int r, t_mlx mlx, t_3point clr)
{
	t_point	temp;
	t_list	*link;
	t_point	link_pt;


	while (room)
	{
		ft_pntset(&temp, get_room(room)->x, get_room(room)->y);
//		printf("%s %d, %d\n",get_room(room)->name, get_room(room)->x, get_room(room)->y);
		brez_circle(mlx, r, temp, clr);
		link = get_room(room)->link_list;
		while (link)
		{
			ft_pntset(&link_pt, get_room(link)->x, get_room(link)->y);
			plotLine(temp, link_pt, clr, mlx);
			link = link->next;
		}
		room = room->next;
	}
}

int	main(void)
{
	t_mlx		mlx;
	t_all		all;
	t_point		pnt;
	t_3point	clr;
	t_farm		*farm;
	t_point p0;
	t_point p1;


	farm = parser();
	init(&mlx);
	all.room = farm->room;
	all.mlx = mlx;
	ft_3pntset(&clr, 127,127,127);


	draw_farm(all.room, 20, all.mlx, clr);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, deal_key, &all);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, ft_end, NULL);
	mlx_loop(mlx.mlx_ptr);
}

