#include "lem_in.h"

void	print_ant_path(t_ant *ant, int ant_count)
{
	int		i;
	int		j;
	t_path	*path;

	i = 0;
	while (i < ant_count)
	{
		path = ant->path[i];
		j = 0;
		ft_putstr("path ant");
		ft_putnbr(i + 1);
		ft_putendl("");
		while (j < path->size)
		{
			ft_putstr(path->ar[j]->name);
			j++;
		}
		ft_putendl("");
		ft_putstr("pos ");
		ft_putnbr(ant->pos[i]);
		ft_putendl("");
		i++;
	}
}
