/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_finder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:20:49 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/07 11:32:24 by sdremora         ###   ########.fr       */
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
}				t_state;

/*
**	--------------------------path_finder.c-------------------------------
*/

t_list			*path_finder(t_farm *farm);

/*
**	--------------------------path_finder.c-------------------------------
*/

int				marker(t_list *room_lst, int step);

/*
**	--------------------------path_utils.c-------------------------------
*/

void			path_add(t_path *path, t_room *add_room);
t_path			*path_new(int path_size);
void			path_to_lst(t_list **lst, t_path *path);
void			path_resize(t_path *path, int new_ar_size);
t_path			*path_copy(t_path *path);

/*
**	--------------------------path_logic.c-------------------------------
*/

void			path_logic(t_list **res_lst, t_farm *farm);

/*
**	--------------------------path_finder_genpath.c-----------------------
*/

t_path			*path_getnew(t_farm *farm);
void			path_free(t_list *path_lst);

/*
**	--------------------------path_resolve_logic.c-----------------------
*/

void			resolve_gen(t_farm *farm, t_list **resolve_lst,\
							t_list **path_lst);

/*
**	--------------------------path_resolve_utils.c-----------------------
*/

int				get_flow(t_farm *farm);
void			resolve_clean(t_resolve *resolve);
t_resolve		*resolve_ini(int flow_count);
void			resolve_free(t_list *resolve_lst);

t_state	*state_ini(t_farm *farm);

int	lstlen(t_list *lst); //удалить
#endif
