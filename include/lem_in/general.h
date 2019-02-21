
#ifndef GENERAL_H
# define GENERAL_H

# include "libft.h"

typedef struct	t_room
{
	char		*name;
	int 		x;
	int			y;
	int			is_empty;
	t_list		*conn;
	int			type;
}				s_room;


/*
typedef struct		t_farm
{
	s_room			*room;
	struct t_farm	*next;
}					s_farm;
*/

typedef struct	t_ant
{
	s_room		room;
	char		*path;
	int			has_path;
}				s_ant;

typedef	struct	t_path
{
	int			nb;
	t_list		*path;
}				s_path;

void	printer(void);

#endif