/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:28:02 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/19 14:17:29 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	move_ants(t_all *all)
{
	int		j;
	t_ant	*ant;

	ant = all->ant;
	j = 0;
	while (j < all->ant_count)
	{
		if (ant->pos[j] + 1 < ant->path[j]->size
				&& ant->path[j]->ar[ant->pos[j] + 1]->is_empty)
		{
			ant->path[j]->ar[ant->pos[j]]->is_empty = 1;
			if (all->start_count > 0
				&& ant->path[j]->ar[ant->pos[j]] == all->start)
				all->start_count--;
			if (ant->pos[j] + 1 != ant->path[j]->size - 1)
				ant->path[j]->ar[ant->pos[j] + 1]->is_empty = 0;
			if (ant->path[j]->ar[ant->pos[j] + 1] == all->end)
				all->end_count++;
			ft_strdel(&(ant->path[j]->ar[ant->pos[j]]->ant_name));
			ant->path[j]->ar[ant->pos[j] + 1]->
				ant_name = ft_strjdelsnd("L", ft_itoa(j + 1));
			ant->pos[j] += 1;
		}
		j++;
	}
}

int		deal_key(int key, t_all *all)
{
	t_mlx		mlx;
	static int	i = 0;

	mlx = all->mlx;
	if (key == 53)
		exit(1);
	else if (key == 49 && all->ant->pos[all->ant_count - 1]
			!= all->ant->path[all->ant_count - 1]->size - 1)
	{
		move_ants(all);
		draw_farm(all->room, 20, all->mlx, all->pic);
		i++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	draw_names(all, i);
	return (0);
}

char	**read_ant(char *fname)
{
	char	temp[2048];
	int		fd;
	int		ret;

	fd = open(fname, O_RDONLY);
	ret = read(fd, temp, 2046);
	temp[2047] = 0;
	return (ft_strsplit(temp, '\n'));
}

int		main(void)
{
	t_mlx		mlx;
	t_all		all;
	t_farm		*farm;

	all.pic = read_ant("ant");
	farm = parser();
	all.ant = solver_vis(resolve_finder(farm), farm->ant_count);
	all.start = farm->start;
	all.end = farm->end;
	all.end_count = 0;
	init(&mlx);
	all.room = farm->room;
	all.mlx = mlx;
	all.ant_count = farm->ant_count;
	all.start_count = all.ant_count;
	draw_farm(all.room, 20, all.mlx, all.pic);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	draw_names(&all, 0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, deal_key, &all);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, ft_end, NULL);
	mlx_loop(mlx.mlx_ptr);
	ft_arrstrdel(all.pic);
}
