
#include "lem_in.h"

int main()
{
	t_farm	*farm;
	t_list	*resolve;
	char	*result;

	farm = parser();
	resolve = way_finder(farm);
	result = solver(resolve, farm->ant_count);
	print_map(farm);
	printer(result);
	return (0);

}
