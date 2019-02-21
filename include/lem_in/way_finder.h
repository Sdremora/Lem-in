
#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

typedef	struct	s_resolve
{
	int			nb;
	t_list		*path;
}				t_resolve;

t_resolve	*way_finder(t_farm *farm);

#endif
