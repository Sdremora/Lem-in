/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_finder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:20:49 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/11 11:11:16 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

typedef struct	s_path
{
	t_room		**ar;
	int			size;
	int			max_size;
	int			id;
}				t_path;

typedef	struct	s_resolve
{
	t_path		**path_ar;
	int			flow_count;
	int			move_count;
	t_list		**rooms_har;
	int			har_size;
}				t_resolve;

typedef struct	s_state
{
	t_list		**res_ar;
	t_list		*last_one;
	int			cur_flow;
	int			max_flow;
	int			target_flow;
	int			res_count;
}				t_state;

/*
**	--------------------------path_resolve_logic.c-----------------------
*/

t_list			*resolve_finder(t_farm *farm);

/*
**	--------------------------path_gen.c-----------------------
*/

t_path			*path_getnew(t_farm *farm);

/*
**	--------------------------path_utils.c-------------------------------
*/

t_path			*path_new(int path_size, int path_id);
t_path			*path_copy(t_path *path);
void			path_add(t_path *path, t_room *add_room);
void			path_resize(t_path *path, int new_ar_size);
int		lstlen(t_list *lst); // удалить

/*
**	----------------------path_resolve_utils.c-------------------------
*/

t_state			*state_ini(t_farm *farm);
t_resolve		*resolve_ini(int flow_count);
void			resolve_free(t_resolve *resolve);

#endif
