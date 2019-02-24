
#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

typedef	struct	s_resolve
{
	int			nb;
	t_arrnum	*path;
}				t_resolve;

void    way_finder(t_farm *farm, t_list **res, int start, int prev);

#endif
