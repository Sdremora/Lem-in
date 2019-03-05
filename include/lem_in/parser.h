/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:07:19 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/04 16:43:57 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "general.h"

typedef struct	s_connlst
{
	t_list	*conn;
	int		id;
	char	*name;
}				t_connlst;

t_farm			*parser(void);
void			farm_cleaner(t_farm *farm);
char			*add_map(char *map, char *str, int flag);
char			*add_comms(char *map, char *str);

void			read_commands(char *str, int *type);
t_room			*get_room(t_list *farm);
void			farm_checker(t_farm *farm);
int				get_nb(char *str);
int				ft_check_duplication(char *name, t_list *farm);

char			*add_map(char *map, char *str, int flag);
char			*add_comms(char *map, char *str);
int				read_ant_count(t_farm *res, char **str);

void			farm_printer(t_farm *res);
void			end_start_conn_printer(t_farm *res);

#endif
