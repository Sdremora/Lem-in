
#ifndef SOLVER_H
# define SOLVER_H

# include "general.h"

typedef struct	s_ant
{
	t_path	**path;
	int		*pos;
//	t_room	**room;
}				t_ant;

void			solver(t_list *resolve, int ant_count);
void			print_map(t_farm *farm);
void			print_res(t_resolve *res, int ant_count);
int				step_counter(t_resolve *res, int ant_count);

#endif
