
#ifndef WAY_FINDER_H
# define WAY_FINDER_H

# include "general.h"

# define E_NOPATH -5

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

t_list	*path_finder(t_farm *farm, t_list **path_lst);
int		marker(t_list *room_lst, int step);
t_path	*path_getnew(t_farm	*farm);
void	path_to_lst(t_list **lst, t_path *path);
void	path_free(t_list	*path_lst);

#endif
