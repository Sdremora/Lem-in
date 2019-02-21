/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:11:19 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/21 17:36:05 by hharvey          ###   ########.fr       */
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
		if (ft_strequ(((t_temp*)farm->content)->room->name, name))
			return (1);
		farm = farm->next;
	}
	return (0);
}

t_room  *get_room(t_list *farm)
{
	return (((t_temp*)(farm->content))->room);
}

void	read_connection(t_list **farm, char *str)
{
	char	**temp;
	t_list	*lst;

	temp = ft_strsplit(str, '-');
	lst = *farm;
	while (lst && !ft_strequ(get_room(lst)->name, temp[0]))
		lst = lst->next;
	if (!lst)
		ft_error();
	ft_lstadd(&(((t_temp*)lst->content)->conn), ft_lstnew(temp[1], sizeof(char*)));

	lst = *farm;
	while (lst && !ft_strequ(get_room(lst)->name, temp[1]))
		lst = lst->next;
	if (!lst)
		ft_error();
	ft_lstadd(&(((t_temp*)lst->content)->conn), ft_lstnew(temp[0], sizeof(char*)));
	free(temp);
}

void	temp_init(t_temp *temp, t_room *room, t_list *conn)
{
	temp->room = room;
	temp->conn = conn;
}	

void    read_room(t_list **farm, char *str, int *type)
{
	t_room  *room;
	t_list  *temp_list;
	char	**split;
	t_temp	*temp;

	room = (t_room*)malloc(sizeof(t_room));
	temp = (t_temp*)malloc(sizeof(t_temp));
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
	temp_init(temp, room, 0);
	temp_list = ft_lstnew(temp, sizeof(*temp));
	free(temp);
	ft_lstadd(farm, temp_list);
	*type = 0;
}

void	temp_to_array(t_list *farm, t_farm *res)
{
	int		len;
	t_room	*room;

	len = ft_lstlen(farm);
	room = (t_room*)malloc(sizeof(t_room) * len);
	res->size = len;
//	whil 

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
		else if (*str != 'L' && ft_strwrdcnt(str, '-') == 2 && farm)
			read_connection(&farm, str);
		else
		{
			free(str);
			break ;
		}
		free(str);
	}
//	printf("%p", ((t_temp*)(farm->content))->room->name);
	while (farm)
	{
		printf("name %s\n", get_room(farm)->name);
		ft_lstprint(((t_temp*)farm->content)->conn);
		farm = farm->next;
	}
	temp_to_array(farm,res);

	/*
	while (farm)
	{
		printf("name %s\n", get_room(farm)->name);
		if (get_room(farm)->type == 1)
			printf("start\n");
		if (get_room(farm)->type == 2)
			printf("end\n");
		test = get_room(farm)->conn;
		while (test)
		{
			printf("%s-%s\n", get_room(farm)->name, (char*)test->content);
			test = test->next;
		}
		farm = farm->next;
	}
	*/
	return (res);
}
