
#include "lem_in.h"

void		error_handle(int error_index)
{
	char	*error_str;

	if (error_index == E_NOPATH)
		error_str = "ERROR: no path.";
	else if (error_index == E_BADMAP)
		error_str = "ERROR: invalid map.";
	else if (error_index == E_NOMEM)
		error_str = "ERROR: no mem.";
	else
		error_str = "ERROR";
	ft_putendl(error_str);
	exit(error_index);
}

/*
**	path_getnew(NULL) clean inner static variable.
*/

static void	farm_free(t_farm *farm, t_list *res_lst, t_list *path_lst)
{
	path_getnew(NULL);
	path_free(path_lst);
	resolve_free(res_lst);
	farm_cleaner(farm);
}

int			main(void)
{
	t_farm	*farm;
	t_list	*resolve_lst;
	t_list	*path_lst;

	farm = parser();
	resolve_lst = path_finder(farm, &path_lst);
	print_map(farm);
 	solver(resolve_lst, farm->ant_count);
	//farm_free(farm, resolve_lst, path_lst);
	return (0);
}
