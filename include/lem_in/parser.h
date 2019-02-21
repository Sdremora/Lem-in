
#ifndef PARSER_H
# define PARSER_H

# include "general.h"

typedef struct			t_clst
{
	char				*name;
	t_list				*conn;
	struct t_clst		*next;
}						s_clst;

s_farm	*parser(void);

#endif
