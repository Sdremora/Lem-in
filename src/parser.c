
#include "lem_in.h"

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

void	room_cleaner(t_room *room)
{
	free(room->name);
	ft_lstdel(&(room->link_list), ft_lstdelfun);
	ft_lstdel(&(room->pre_list), ft_lstdelfun);
	free(room);
}

void	farm_list_cleaner(t_list *farm)
{
	t_list *temp;

	while (farm)
	{
		temp = farm;
		room_cleaner(farm->content);
		farm = farm->next;
		free(temp);
	}
}

void	farm_cleaner(t_farm *farm)
{
	farm_list_cleaner(farm->room);
	free(farm);
}

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

t_room	*get_room(t_list *farm)
{
	return (farm->content);
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

void	read_room(t_list **farm, char *str, int *type, t_farm *res)
{
	t_room	*room;
	t_list	*temp_list;
	char	**split;

	room = (t_room*)malloc(sizeof(t_room));
	split = ft_strsplit(str, ' ');
	room->name = ft_strdup(split[0]);
	room->x = get_nb(split[1]);
	room->y = get_nb(split[2]);
	room->link_list = 0;
	room->step = -1;
	room->pre_list = 0;
	room->is_empty = 1;
	ft_arrstrdel(split);
	room->type = *type;
	if (*type == 1)
		res->start = room;
	else if (*type == 2)
		res->end = room;
	if (ft_check_duplication(room->name, *farm))
		ft_error();
	temp_list = (t_list*)malloc(sizeof(t_list));
	temp_list->content = room;
	ft_lstadd(farm, temp_list);
	*type = 0;
}

void	read_connection(char *str, t_list *farm)
{
	char	**split;
	t_list	*temp_lst;
	t_list	*lst1;
	t_list	*lst2;

	split = ft_strsplit(str, '-');
	if (!ft_strequ(split[0], split[1]))
	{
		lst1 = 0;
		lst2 = 0;
		while ((!lst1 || !lst2) && farm)
		{
			if (ft_strequ(((t_room*)farm->content)->name, split[0]))
				lst1 = farm;
			if (ft_strequ(((t_room*)farm->content)->name, split[1]))
				lst2 = farm;
			farm = farm->next;
		}
		if (!lst1 || !lst2)
			ft_error();
		temp_lst = (t_list*)malloc(sizeof(t_list));
		temp_lst->content = lst2->content;
		ft_lstadd(&((t_room*)lst1->content)->link_list, temp_lst);
		temp_lst = (t_list*)malloc(sizeof(t_list));
		temp_lst->content = lst1->content;
		ft_lstadd(&((t_room*)lst2->content)->link_list, temp_lst);
	}
	ft_arrstrdel(split);
}

char 	*add_map(char *map, char *str)
{
	int		len;
	char	*res;
	int		i;
	int		len_map;
	int		len_str;

	i = 0;
	len_map = ft_strlen(map);
	len_str = ft_strlen(str);
	len = len_map + len_str;
	res = (char*)malloc(len + 2);
	while (i < len)
	{
		if (i < len_map)
			res[i] = map[i];
		else if (i < len_map + len_str)
			res[i] = str[i - len_map];
		i++;
	}
	res[i] = '\n';
	res[i + 1] = 0;
	free(map);
	free(str);
	return (res);
}

t_farm	*parser(void)
{
	char	*str;
	int		type;
	t_list	*farm;
	t_farm	*res;

	farm = 0;
	res = (t_farm*)malloc(sizeof(t_farm));
	res->map = ft_strdup("");
	res->start = 0;
	res->end = 0;
	type = 0;
	res->ant_count = -1;
	while (get_next_line(0, &str))
	{
		if (*str == '#')
			read_commands(str, &type);
		else if (ft_isnumber(str) && res->ant_count == -1)
			res->ant_count = ft_atoi(str);
		else if (*str != 'L' && ft_strwrdcnt(str, ' ') == 3)
			read_room(&farm, str, &type, res);
		else if (*str != 'L' && ft_strwrdcnt(str, '-') == 2 && farm)
			read_connection(str, farm);
		else
		{
			free(str);
			break ;
		}
		res->map = add_map(res->map, str);
//		free(str);
	}
	res->room = farm;
	farm_checker(res);
	return (res);
}
