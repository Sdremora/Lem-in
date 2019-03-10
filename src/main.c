
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

void		path_to_lst(t_list **lst_head, t_path *path)
{
	t_list	*node;

	node = ft_lstput(path, sizeof(t_path));
	if (node == NULL)
		error_handle(E_NOMEM);
	ft_lstadd(lst_head, node);
}

int			ft_lstisexist(t_list *lst_head, void *content)
{
	while (lst_head)
	{
		if (lst_head->content == content)
			return (1);
		lst_head = lst_head->next;
	}
	return (0);
}
void		result_free(t_list	*res_lst)
{
	t_list		*path_lst;
	t_list		*temp;
	t_resolve	*resolve;
	t_path		*path;
	int			i;

	path_lst = NULL;
	while (res_lst)
	{
		temp = res_lst->next;
		resolve = (t_resolve *)res_lst->content;
		i = 0;
		while (i < resolve->flow_count)
		{
			path = resolve->path_ar[i];
			if (!ft_lstisexist(path_lst, path))
				path_to_lst(&path_lst, path);
			i++;
		}
		resolve_free(resolve);
		free(res_lst);
		res_lst = temp;
	}
	while (path_lst)
	{
		temp = path_lst->next;
		path = (t_path *)path_lst->content;
		free(path->ar);
		free(path);
		free(path_lst);
		path_lst = temp;
	}
}

static void	farm_free(t_farm *farm, t_list *res_lst)
{
	t_list	*next;

	result_free(res_lst);
	path_getnew(NULL);
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
	
	resolve_lst = resolve_finder(farm);
	if (resolve_lst == NULL)
		error_handle(E_NOPATH);
	print_map(farm);
	if (argc != 1)
		flags_handle(argc, argv, flags);
	if (flags[F_PR])
		print_res_lst(resolve_lst);
	solver(resolve_lst, farm->ant_count);
	farm_free(farm, resolve_lst);
	return (0);
}
