
#include "lem_in.h"

void    printer(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_map(t_farm *farm)
{
	printer(farm->map);
	ft_putendl("");
}
