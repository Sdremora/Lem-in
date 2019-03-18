/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:10:57 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/18 16:59:46 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "general.h"

typedef struct	s_ant
{
	t_path	**path;
	int		*pos;
}				t_ant;

void			solver(t_list *resolve, int ant_count);
void			print_map(t_farm *farm);
void			print_res(t_resolve *res, int ant_count);
int				step_counter(t_resolve *res, int ant_count);

void			print_resolve(t_resolve *res);
void			print_all_resolves(t_list *resolve);
void			path_max_size(t_resolve *res);

t_ant			*ant_init(t_resolve *res, int ant_count);

#endif
