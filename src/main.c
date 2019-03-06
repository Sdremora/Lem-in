
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

static void	farm_free(t_farm *farm, t_list *res_lst)
{
	resolve_free(res_lst);
	farm_cleaner(farm);
}

void	flags_handle(int argc, char **argv, int *flags)
{
	int i;

	i = 1;
	while (i < argc && i < 5)
	{
		if (ft_strequ(argv[i], "-pr"))
			flags[F_PR] = 1;
		i++;
	}
}

void		print_res_lst(t_list *res_lst)
{
	int 		n;
	int 		i;
	t_path		*path;
	t_resolve	*resolve;

	while (res_lst)
	{
		i = 0;
		resolve = (t_resolve *)res_lst->content;
		ft_putstr("==>\t");
		while (i < resolve->flow_count)
		{
			path = resolve->path_ar[i++];
			n = 0;
			while (n < path->size)
			{
				ft_putstr(path->ar[n]->name);
				if (path->ar[n++]->type != R_END)
					ft_putstr(" -> ");
			}
			ft_putstr("\n\t");
		}
		ft_putstr("\n");
		res_lst = res_lst->next;
	}
}

int			main(int argc, char **argv)
{
	t_farm	*farm;
	t_list	*resolve_lst;
	t_list	*path_lst;
	int		flags[5];

	ft_bzero(flags, 5);
	farm = parser();
	farm_printer(farm);
	end_start_conn_printer(farm);

	resolve_lst = path_finder(farm);
	print_map(farm);
	if (argc != 1)
		flags_handle(argc, argv, flags);
	if (flags[F_PR])
		print_res_lst(resolve_lst);
	solver(resolve_lst, farm->ant_count);
	farm_free(farm, resolve_lst);
	return (0);
}
