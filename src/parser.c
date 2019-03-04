
#include "lem_in.h"

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
		error_handle(E_BADMAP);
	temp_list = (t_list*)malloc(sizeof(t_list));
	temp_list->content = room;
	ft_lstadd(farm, temp_list);
	*type = 0;
}

void	read_connection(char *str, t_list *farm)
{
	char	**split;
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
			error_handle(E_BADMAP);
		ft_lstadd(&((t_room*)lst1->content)->link_list,
				ft_lstput(lst2->content, lst2->content_size));
		ft_lstadd(&((t_room*)lst2->content)->link_list,
				ft_lstput(lst1->content, lst1->content_size));
	}
	ft_arrstrdel(split);
}

int		read_all_cons(t_farm *res, char **str, t_list *farm)
{
	read_connection(*str, farm);
	res->map = add_map(res->map, *str, 0);
	while (get_next_line(0, str))
		if (**str == '#')
		{
			if (ft_strequ(*str, "##start") || ft_strequ(*str, "##end"))
			{
				free(*str);
				return (-1);
			}
			else
				res->map = add_comms(res->map, *str);
		}
		else if (**str != 'L' && ft_strwrdcnt(*str, '-') == 2 && farm)
		{
			read_connection(*str, farm);
			res->map = add_map(res->map, *str, 0);
		}
		else
		{
			free(*str);
			return (-1);
		}
	return (1);
}

int		read_rooms(t_farm *res, char **str, t_list **farm)
{
	int		type;

	type = 0;
	while (get_next_line(0, str))
	{
		if (**str == '#')
			read_commands(*str, &type);
		else if (**str != 'L' && ft_strwrdcnt(*str, ' ') == 3)
			read_room(farm, *str, &type, res);
		else if (**str != 'L' && ft_strwrdcnt(*str, '-') == 2 && *farm)
			return (read_all_cons(res, str, *farm));
		else
			return (0);
		res->map = add_map(res->map, *str, 0);
	}
	return (1);
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
	res->ant_count = 0;
	if (!read_ant_count(res, &str) || !read_rooms(res, &str, &farm))
	{
		free(str);
		free(res->map);
		free(res);
		error_handle(E_BADMAP);
	}
	res->room = farm;
	farm_checker(res);
	return (res);
}
