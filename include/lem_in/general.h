
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
	int			is_empty;
	t_list		*link_list;
	t_list		*pre_list;
	t_arrnum	*conn;
	int			type;
}				t_room;

typedef struct		s_farm
{
	t_room			**room;
	int				ant_count;
	int				size;
}					t_farm;

typedef struct	s_ant
{
	t_room		room;
	char		*path;
	int			has_path;
}				t_ant;

void	printer(void);
void	error_handle(int error_index, char *error_str);

#endif
