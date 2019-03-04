
#include "lem_in.h"

void	read_commands(char *str, int *type)
{
	static int	has_start = 0;
	static int	has_end = 0;

	if (ft_strequ(str, "##start") && !has_start)
	{
		has_start = 1;
		*type = R_START;
	}
	else if (ft_strequ(str, "##start") && has_start)
		ft_error();
	else if (ft_strequ(str, "##end") && !has_end)
	{
		has_end = 1;
		*type = R_END;
	}
	else if (ft_strequ(str, "##end") && has_end)
		ft_error();
}

t_room	*get_room(t_list *farm)
{
	return (farm->content);
}

int		get_nb(char *str)
{
	long long int	nb;
	int				sgn;

	nb = 0;
	sgn = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sgn *= -1;
		str++;
	}
	if (*str == 0)
		ft_error();
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		if ((nb > 2147483647 && sgn == 1) || (nb > 2147483648 && sgn == -1))
			ft_error();
		str++;
	}
	if (*str != 0)
		ft_error();
	return (nb * sgn);
}

void	farm_checker(t_farm *farm)
{
	if (!farm->room)
		ft_error();
	if (farm->ant_count <= 0)
		ft_error();
	if (!farm->start)
		ft_error();
	if (!farm->end)
		ft_error();
}

int		ft_check_duplication(char *name, t_list *farm)
{
	while (farm)
	{
		if (ft_strequ(get_room(farm)->name, name))
			return (1);
		farm = farm->next;
	}
	return (0);
}