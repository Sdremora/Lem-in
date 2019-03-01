
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
	int			type;
	int			is_empty;
}				t_room;

typedef struct		s_farm
{
	t_list			*room;
	int				ant_count;
	int				size;
	t_room			*start;
	t_room			*end;
	char			*map;
}					t_farm;

typedef    enum    e_room_types
{
					R_DEF,
					R_START,
					R_END
}					t_room_types;

void	printer(char *result);
void	error_handle(int error_index, char *error_str);
t_room	*get_room(t_list *farm);


#endif
