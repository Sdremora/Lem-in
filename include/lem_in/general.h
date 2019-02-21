/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:21:40 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/21 17:21:42 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "libft.h"

typedef struct	s_room
{
	char		*name;
	int 		x;
	int			y;
	int			is_empty;
	int			*conn;
	int			type;
}				t_room;

typedef struct		s_farm
{
	s_room			*room;
	int				ant_count;
	int				size;
}					t_farm;

typedef struct	s_ant
{
	s_room		room;
	char		*path;
	int			has_path;
}				t_ant;

void	printer(void);

#endif
