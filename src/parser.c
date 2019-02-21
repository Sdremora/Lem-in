/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:11:19 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/21 13:45:33 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     read_commands(char *str)
{
	if (ft_strequ(str, "##start"))
		return (1);
	else if (ft_strequ(str, "##end"))
		return (2);
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

int		ft_check_duplication(char *name, t_list *farm)
{
	while (farm)
	{
		if (ft_strequ(farm->content, name))
			return (1);
		farm = farm->next;
	}
	return (0);
}

void    read_connection(s_clst **clst, char *str, t_list *farm)
{
	char    **temp;
	s_clst  *room_clst;

	temp = ft_strsplit(str, '-');


	room_clst = *clst;
	while (room_clst && !ft_strequ(room_clst->name, temp[0]))
		room_clst = room_clst->next;
	if (!room_clst)
	{
		ft_lstadd(&(room_clst->conn), ft_lstnew(temp[1], sizeof(char*)));
		room_clst->name = temp[0];
	}
	else
		ft_lstadd(&(room_clst->conn), ft_lstnew(temp[1], sizeof(char*)));

	room_clst = *clst;
	while (room_clst && !ft_strequ(room_clst->name, temp[1]))
		room_clst = room_clst->next;
	if (!room_clst)
	{
		ft_lstadd(&(room_clst->conn), ft_lstnew(temp[0], sizeof(char*)));
		room_clst->name = temp[1];
	}
	else
		ft_lstadd(&(room_clst->conn), ft_lstnew(temp[0], sizeof(char*)));
	free(temp);
}

void    read_room(t_list **farm, char *str, int *type)
{
	s_room  *room;
	t_list  *temp;
	char	**split;

	ft_putendl(str);
	room = (s_room*)malloc(sizeof(s_room));
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
	temp = ft_lstnew(room, sizeof(s_room));
	free(room);
	ft_lstadd(farm, temp);
	*type = 0;
}

s_farm	*parser()
{
	char	*str;
	int		type;
	t_list	*farm;
	s_farm	*res;
	s_clst	*clst;

	clst = 0;
	farm = 0;
	res = (s_farm*)malloc(sizeof(s_farm));
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
		else if (*str != 'L' && ft_strwrdcnt(str, '-') == 2 && farm)
			read_connection(&clst, str, farm);
		else
		{
			free(str);
			break ;
		}
		free(str);
	}
	return (res);
}
