
#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

# define E_NOPATH -5
# define E_NOPATH_STR "ERROR\n"

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
	int			cur_flow;
	int			move_count;
}				t_resolve;

t_list	*way_finder(t_farm *farm);
int		marker(t_list *room_lst, int step);

#endif
