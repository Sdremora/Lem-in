/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:07:55 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/18 14:15:06 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	farm_free(t_farm *farm, t_list *res_lst)
{
	t_list	*next;

	while (res_lst)
	{
		next = res_lst->next;
		free(res_lst);
		res_lst = next;
	}
	resolve_finder(NULL);
	path_getnew(NULL);
	farm_cleaner(farm);
}

static void	flags_handle(int argc, char **argv, int *flags)
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

static void	print_res_lst(t_list *res_lst)
{
	int			n;
	int			i;
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
	int		flags[5];

	ft_bzero(flags, 5);
	if (argc != 1)
		flags_handle(argc, argv, flags);
	farm = parser();
	resolve_lst = resolve_finder(farm);
	if (resolve_lst == NULL)
	{
		farm_free(farm, resolve_lst);
		error_handle(E_NOPATH);
	}
	print_map(farm);
	if (flags[F_PR])
		print_res_lst(resolve_lst);
	solver(resolve_lst, farm->ant_count);
	farm_free(farm, resolve_lst);
	return (0);
}
