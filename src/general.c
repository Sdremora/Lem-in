
#include "lem_in.h"

#include <stdio.h>

void	error_handle(int error_index, char *error_str)
{
	printf("%s\n", error_str);
	exit(error_index);
}
