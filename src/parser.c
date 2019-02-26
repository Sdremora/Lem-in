
#include "lem_in.h"

void	room_cleaner(t_room *room)
{
	free(room->name);
	ft_lstdel(&(room->link_list), ft_lstdelfun);
	ft_lstdel(&(room->pre_list), ft_lstdelfun);
	free(room);
}

void	farm_cleaner(t_list *farm)
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

int     read_commands(char *str)
{
	static int	has_start = 0;
	static int	has_end = 0;

	if (ft_strequ(str, "##start") && !has_start)
	{
		has_start = 1;
		return (1);
	}
	else if (ft_strequ(str, "##end") && !has_end)
	{
		has_end = 1;
		return (2);
	}
	else
		ft_error();
	return (0);
}

int         get_nb(char *str)
{
	long long int   nb;
	int             sgn;

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

 t_room  *get_room(t_list *farm)
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

void    read_room(t_list **farm, char *str, int *type, t_farm *res)
{
	t_room  *room;
	t_list  *temp_list;
	char	**split;

	room = (t_room*)malloc(sizeof(t_room));
	split = ft_strsplit(str, ' ');
	room->name = ft_strdup(split[0]);
	room->x = get_nb(split[1]);
	room->y = get_nb(split[2]);
	room->link_list = 0;
	room->step = -1;
	room->pre_list = 0;
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

/*
void	temp_to_array(t_list *farm, t_farm *res)
{
	int		len;
	t_room	**room;
	t_list	*temp;
	int i;

	i = 0;
	len = ft_lstlen(farm);
	room = (t_room**)malloc(sizeof(t_room*) * len);
	res->size = len;
	while (i < len)
	{
		room[i] = get_room(farm);
		temp = farm;
		farm = farm->next;
		free(temp);
		i++;
	}
	res->room = room;
}

int		get_id(t_farm *res, char *str)
{
	int i;

	i = 0;
	while (i < res->size)
	{
		if (ft_strequ(res->room[i]->name, str))
			return (i);
		i++;
	}
	ft_error();
	return (-1);
}
*/

void	read_connection(char *str, t_list *farm)
{
	char	**split;
	t_list	*temp_lst;
	t_list	*lst1;
	t_list	*lst2;

	split = ft_strsplit(str, '-');
	if (!ft_strequ(split[0],split[1]))
	{
		lst1 = 0;
		lst2 = 0;
		while (!lst1 || !lst2)
		{
			if (ft_strequ(((t_room*)farm->content)->name, split[0]))
				lst1 = farm;
			if (ft_strequ(((t_room*)farm->content)->name, split[1]))
				lst2 = farm;
			farm = farm->next;
		}
		temp_lst = (t_list*)malloc(sizeof(t_list));
		temp_lst->content = lst2->content;
		ft_lstadd(&((t_room*)lst1->content)->link_list, temp_lst);
		temp_lst = (t_list*)malloc(sizeof(t_list));
		temp_lst->content = lst1->content;
		ft_lstadd(&((t_room*)lst2->content)->link_list, temp_lst);
	}
	ft_arrstrdel(split);
}

t_farm	*parser()
{
	char	*str;
	int		type;
	t_list	*farm;
	t_farm	*res;
	t_list	*test;

	farm = 0;
	res = (t_farm*)malloc(sizeof(t_farm));
	type = 0;
	res->ant_count = -1;
	while (get_next_line(0, &str))
	{
		if (*str == '#' && !ft_strnequ(str, "##", 2));
		else if (ft_isnumber(str) && res->ant_count == -1)
			res->ant_count = ft_atoi(str);
		else if (*str == '#')
			type = read_commands(str);
		else if (*str != 'L' && ft_strwrdcnt(str, ' ') == 3)
			read_room(&farm, str, &type, res);
		else if (*str != 'L' && ft_strwrdcnt(str, '-') == 2 && farm)
			read_connection(str, farm);
		else
		{
			free(str);
			break ;
		}
		free(str);
	}
	res->room = farm;
//	temp_to_array(farm,res);
	while (farm)
	{
		printf("room name: %s\n", ((t_room*)farm->content)->name);
		test = ((t_room*)farm->content)->link_list;
		printf("links: ");
		while (test)
		{
			printf("%s ", ((t_room*)test->content)->name);
			test = test->next;
		}
		printf("\n");
		farm = farm->next;
	}
	return (res);
}
