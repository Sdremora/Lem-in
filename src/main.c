
#include "lem_in.h"

void	resolve_free(t_list	*resolve_lst)
{
	t_list		*next_node;
	t_resolve	*resolve;

	while (resolve_lst)
	{
		next_node = resolve_lst->next;
		resolve = (t_resolve *)resolve_lst->content;
		free(resolve->path_ar);
		free(resolve);
		free(resolve_lst);
		resolve_lst = next_node;
	}
}

int main()
{
	t_farm	*farm;
	t_list	*resolve_lst;
	t_list	*path_lst;
	char	*result;

	farm = parser();
	resolve_lst = path_finder(farm, &path_lst);
	print_map(farm);
	solver(resolve_lst, farm->ant_count);
	path_getnew(NULL);
	path_free(path_lst);
	resolve_free(resolve_lst);
	farm_cleaner(farm);

	return (0);

}
