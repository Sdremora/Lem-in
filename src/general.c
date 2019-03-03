
#include "lem_in.h"

#include <stdio.h>

void	error_handle(int error_index)
{
	char	*error_str;

	if (error_index == E_NOPATH)
		error_str = "ERROR";
	else if (error_index == E_NOMEM)
		error_str = "ERROR: no mem";
	else
		error_str = "ERROR";
	ft_putendl(error_str);
	exit(error_index);
}
