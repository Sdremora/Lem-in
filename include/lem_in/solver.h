
#ifndef SOLVER_H
# define SOLVER_H

# include "general.h"

char	*solver(t_list *resolve, int ant_count);

void	print_map(t_farm *farm);

typedef struct		s_ant
{
	t_path			**path;
	int				*pos;
//	t_room			**room;
}					t_ant;
#endif
