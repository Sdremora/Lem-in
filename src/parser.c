/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:11:19 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/24 15:58:04 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void    read_room(t_list **farm, char *str, int *type)
{
	t_room  *room;
	t_list  *temp_list;
	char	**split;

	room = (t_room*)malloc(sizeof(t_room));
	split = ft_strsplit(str, ' ');
	room->name = ft_strdup(split[0]);
	room->x = get_nb(split[1]);
	room->y = get_nb(split[2]);
	ft_arrstrdel(split);
	room->type = *type;
	room->is_empty = 1;
	room->conn = 0;
	if (ft_check_duplication(room->name, *farm))
		ft_error();
	temp_list = (t_list*)malloc(sizeof(t_list));
	temp_list->content = room;
	ft_lstadd(farm, temp_list);
	*type = 0;
}

void	swap_rooms(t_room **room, int i, int type, int len)
{
	t_room *temp;

	if (type == 1)
	{
		temp = room[0];
		room[0] = room[i];
		room[i] = temp;
	}
	else if (type == 2)
		room[len - 1] = room[i];
}

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
		if (room[i]->type != 0)
			swap_rooms(room, i, room[i]->type, len);
		temp = farm;
		farm = farm->next;
		free(temp);
		if (room[i]->type == 2)
		{
			len -= 1;
			continue;
		}
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

void	read_connection(char *str, t_list *farm, t_farm *res)
{
	char	**split;
	t_list	*temp_lst;
	int		id1;
	int		id2;
	t_list	*lst;

	lst = farm;
	split = ft_strsplit(str, '-');
	id1 = get_id(res, split[0]);
	id2 = get_id(res, split[1]);
	while (!ft_strequ(((t_connlst*)lst->content)->name, split[0]))
		lst = lst->next;
	temp_lst = (t_list*)malloc(sizeof(t_list));
	ft_lstsetnb(temp_lst, id2);
	ft_lstadd(&((t_connlst*)lst->content)->conn, temp_lst);
	lst = farm;
	while (!ft_strequ(((t_connlst*)lst->content)->name, split[1]))
		lst = lst->next;
	temp_lst = (t_list*)malloc(sizeof(t_list));
	ft_lstsetnb(temp_lst, id1);
	ft_lstadd(&((t_connlst*)lst->content)->conn, temp_lst);
	ft_arrstrdel(split);
	free(str);
}

void	s_connlst_set(t_connlst *connlst, int id, char *name, t_list *conn)
{
	connlst->id = id;
	connlst->name = name;
	connlst->conn = conn;
}

void	temp_conn_init(t_list **farm, t_farm *res)
{
	int			i;
	t_connlst	*connlst;
	t_list		*temp;

	i = 0;
	while (i < res->size)
	{
		connlst = (t_connlst*)malloc(sizeof(t_connlst));
		s_connlst_set(connlst, i, res->room[i]->name, 0);
		temp = ft_lstnew(connlst, sizeof(*connlst));
		free(connlst);
		ft_lstadd(farm, temp);
		i++;
	}
}

void	temp_conn_to_arr(t_list *farm, t_farm *res)
{
	t_list		*lst;
	int			i;
	t_arrnum	*arr;

	while (farm)
	{
		arr = ft_ltan_free(((t_connlst*)farm->content)->conn);
		res->room[((t_connlst*)farm->content)->id]->conn = arr;
		lst = farm;
		farm = farm->next;
		ft_lstdelone(&lst, ft_lstdelfun);
	}
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
			read_room(&farm, str, &type);
		else
			break ;
		free(str);
	}
	temp_to_array(farm,res);
	farm = 0;
	temp_conn_init(&farm, res);
	read_connection(str, farm, res);
	while (get_next_line(0, &str))
	{
		if (*str == '#' && !ft_strnequ(str, "##", 2));
		else if (*str != 'L' && ft_strwrdcnt(str, '-') == 2 && farm)
			read_connection(str, farm, res);
		else
		{
			free(str);
			break ;
		}
	}
	temp_conn_to_arr(farm, res);
	int i = 0;
	while (i < res->size)
	{
		printf("name: %s id %d\n", res->room[i]->name, i);
		ft_arrnumprint(*res->room[i]->conn);
		i++;
	}
	return (res);
}
