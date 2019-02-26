
#ifndef GENERAL_H
# define GENERAL_H

# include "libft.h"

# define E_NOMEM -4
# define E_NOMEM_STR "Error: no mem"

typedef struct	s_room
{
	char		*name;
	int 		x;
	int			y;
	t_list		*link_list;
	t_list		*pre_list;
	int			step;
}				t_room;

typedef struct		s_farm
{
	t_room			**room;
	int				ant_count;
	int				size;
	t_room			*start;
	t_room			*end;
}					t_farm;

void	printer(char *result);
void	error_handle(int error_index, char *error_str);

#endif
