/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mapncount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:07:23 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/14 11:06:04 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_init(t_room *room, char **split)
{
	room->name = split[0];
	room->x = get_nb(split[1]);
	room->y = get_nb(split[2]);
	room->link_list = 0;
	room->is_empty = 1;
	room->hash = 0;
	ft_bzero(room->is_visited, 100);
	free(split[1]);
	free(split[2]);
	free(split);
}

char	*add_map(char *map, char *str, int flag)
{
	int		len;
	char	*res;
	int		i;
	int		len_map;
	int		len_str;

	if (*str == '#' && !flag)
		return (add_comms(map, str));
	i = -1;
	len_map = ft_strlen(map);
	len_str = ft_strlen(str);
	len = len_map + len_str;
	res = (char*)malloc(len + 2);
	while (++i < len)
	{
		if (i < len_map)
			res[i] = map[i];
		else if (i < len_map + len_str)
			res[i] = str[i - len_map];
	}
	res[i] = '\n';
	res[i + 1] = 0;
	free(map);
	free(str);
	return (res);
}

char	*add_comms(char *map, char *str)
{
	if (ft_strnequ(str, "##", 2))
	{
		if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
			return (add_map(map, str, 1));
		else if (ft_strnequ(str, "###", 3))
			return (add_map(map, str, 1));
		else
		{
			free(str);
			return (map);
		}
	}
	return (add_map(map, str, 1));
}

int		read_ant_count(t_farm *res, char **str)
{
	while (!res->ant_count)
	{
		if (get_next_line(0, str) == 1)
		{
			if (**str == '#')
			{
				if (ft_strequ(*str, "##start") || ft_strequ(*str, "##end"))
					return (0);
				else
					res->map = add_comms(res->map, *str);
			}
			else if (ft_isnumber(*str))
			{
				res->ant_count = ft_atoi(*str);
				res->map = add_map(res->map, *str, 0);
			}
			else
				return (0);
		}
		else
		{
			return (-1);
		}
	}
	return (1);
}
