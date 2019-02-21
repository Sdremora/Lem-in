
#ifndef PARSER_H
# define PARSER_H

# include "general.h"

typedef struct	s_temp
{
	t_list		*conn;
	t_room		*room;
}				t_temp;

t_farm	*parser(void);

#endif
