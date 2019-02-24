
#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

typedef	struct	s_resolve
{
	int			nb;
	t_arrnum	*path;
	t_list		*path_list;
	int			flow_count;
	int			move_count;
}				t_resolve;

t_list *way_finder(t_farm *farm);

#endif
