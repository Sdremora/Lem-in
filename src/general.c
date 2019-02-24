
#include "lem_in.h"

void	error_handle(int error_index, char *error_str)
{
	ft_printf("%s\n", error_str);
	exit(error_index);
}
