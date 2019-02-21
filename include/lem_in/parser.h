
#ifndef PARSER_H
# define PARSER_H

# include "general.h"

typedef struct	t_temp
{
	t_list		*conn;
	s_room		*room;
}				s_temp;

s_farm	*parser(void);

#endif
