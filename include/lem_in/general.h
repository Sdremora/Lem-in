/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:10:44 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/14 18:02:54 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "libft.h"

# define E_BADMAP -3
# define E_NOMEM -4
# define E_NOPATH -5
# define E_BADROOM -6

# define F_PR 0

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	t_list			*link_list;
	int				type;
	int				is_empty;
	char			is_visited[100];
	unsigned int	hash;
}				t_room;

typedef struct	s_farm
{
	t_list	*room;
	int		ant_count;
	int		size;
	t_room	*start;
	t_room	*end;
	char	*map;
}				t_farm;

typedef enum	e_room_types
{
	R_DEF,
	R_START,
	R_END
}				t_room_types;

void			printer(char *result);
void			error_handle(int error_index);
t_room			*get_room(t_list *farm);

#endif
