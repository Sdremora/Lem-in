
#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

typedef	struct	t_resolve
{
	int			nb;
	t_list		*path;
}				s_resolve;

t_resolve	*way_finder(t_farm);

#endif