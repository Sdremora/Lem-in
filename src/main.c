
#include "lem_in.h"

int main()
{
	t_farm	*farm;
	t_list	*resolve;
	char	*result;

	farm = parser();
	resolve = way_finder(farm);
	print_map(farm);
	solver(resolve, farm->ant_count);
	return (0);

}
