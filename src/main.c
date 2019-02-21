/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:22:05 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/21 17:34:44 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

/*
int		read_commands(char *str)
{
	if (ft_strequ(str, "##start"))
		return (1);
	else if (ft_strequ(str, "##end"))
		return (2);
	else
		ft_error();
	return (0);
}

int			get_nb(char *str)
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

s_room	*set_room(char *str, int type)
{
	char	**temp;
	s_room	*room;

	room = (s_room*)malloc(sizeof(s_room));
	temp = ft_strsplit(str, ' ');
	room->name = temp[0];
	room->x = get_nb(temp[1]);
	room->y = get_nb(temp[2]);
	room->type = type;
	room->is_empty = 1;
	room->conn = 0;
	free(temp[1]);
	free(temp[2]);
	free(temp);
	return (room);
}

void	read_room(t_list **farm, char *str, int *type)
{
	s_room	*room;
	t_list	*temp;

	room = set_room(str, *type);
	temp = ft_lstnew(room, sizeof(s_room));
	ft_lstadd(farm, temp);
	*type = 0;
}

void	add_room(t_list **room, char *str, int *type)
{
	t_list	*temp;
	int		space_pos;
	char 	*name;


	space_pos = ft_strchr(str, ' ') - str;
	if (!space_pos)
	{
		ft_putendl("empty name");
		exit(1);
	}
	name = ft_strndup(str, space_pos);
	temp = ft_lstnew(name, space_pos);
	if (ft_lstcontfnd(*room, *temp, ft_strequ))
	{
		ft_putendl("duppl");
		exit(1);
	}
	ft_lstadd(room, temp);
}

s_room  *get_room(t_list *farm)
{
	return (farm->content);
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
	ft_lstadd(&(get_room(lst)->conn), ft_lstnew(temp[1], sizeof(char*)));

	lst = *farm;
	while (lst && !ft_strequ(get_room(lst)->name, temp[1]))
		lst = lst->next;
	if (!lst)
		ft_error();
	ft_lstadd(&(get_room(lst)->conn), ft_lstnew(temp[0], sizeof(char*)));
	free(temp);
}

s_room	*get_room_by_name(t_list *farm, char *str)
{
	while (farm)
	{
		if (ft_strequ(get_room(farm)->name, str))
			return (get_room(farm));
		farm = farm->next;
	}
	ft_error();
	return (0);
}

s_room	*get_start_room(t_list *farm)
{
	while (farm)
	{
		if (get_room(farm)->type == 1)
			return (get_room(farm));
		farm = farm->next;
	}
	ft_error();
	return (0);
}

void	backtrack(s_room *start, s_room *prev, t_list **res, t_list *farm)
{
	s_room	*next;
	t_list	*conn;
	t_list	*temp;
	t_list	**restemp;

	conn = start->conn;
	if (start->type == 2)
	{
		ft_putendl("end_path:");
		ft_lstprint(*res);
		ft_putendl("start_path:");
		return ;
	}
	while (conn)
	{
		if (!prev || !ft_strequ(prev->name, conn->content))
		{
			next = get_room_by_name(farm, conn->content);
			temp = ft_lstnew(next->name, ft_strlen(next->name));
			if (ft_lstcontfnd(*res, *temp, ft_strequ))
			{
				ft_lstdelone(&temp, ft_lstdelfun);
				conn = conn->next;
				continue;
				;
			}
			ft_lstadd(res, temp);
			backtrack(next, start, res, farm);

//			restemp = res;
			*res = (*res)->next;
//			ft_lstdelone(restemp, ft_lstdelfun);
//			*res = (*res)->next;

//			ft_lstdelone(restemp, ft_lstdelfun);

		}
		conn = conn->next;
	}
	return ;
}

*/
/*
int main(int argc, char **argv)
{
	char	*str;;
	int		type;
	t_list	*farm;
	int		ant_count;
	t_list	*test;

	t_list	*room;
	char	**arr_names;
	room = 0;
	ant_count = -1;
	type = 0;
	farm = 0;
	while (get_next_line(0, &str))
	{
		if (*str == '#' && !ft_strnequ(str, "##", 2));
		else if (ft_isnumber(str) && ant_count == -1)
			ant_count = ft_atoi(str);
		else if (*str == '#')
			type = read_commands(str);
		else if (*str != 'L' && ft_strwrdcnt(str, ' ') == 3)
		{
			add_room(&room, str, &type);
			read_room(&farm, str, &type);
		}
		else if (*str != 'L' && ft_strwrdcnt(str, '-') == 2 && farm)
			read_connection(&farm, str);
		else
			break ;
	}

	t_list *res = 0;
	backtrack(get_start_room(farm), 0, &res, farm);

	while (farm)
	{
		printf("name %s\n", get_room(farm)->name);
		if (get_room(farm)->type == 1)
			printf("start\n");
		if (get_room(farm)->type == 2)
			printf("end\n");
		test = get_room(farm)->conn;
//		ft_lstprint(test);
		while (test)
		{
			printf("%s-%s\n", get_room(farm)->name, (char*)test->content);
			test = test->next;
		}
		farm = farm->next;
	}
	arr_names = ft_ltas(room); //list to array
	ft_arrstrprnt(arr_names);
	return (0);
}
*/

int main(int argc, char **argv)
{
	t_farm *farm;

	farm = parser();
	/*
	s_farm	*farm;

	farm = parser(argc, argv);
	way_finder();
	solver();
	printer();
	ft_putnbr(128);
	*/
	return (0);
}

