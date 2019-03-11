/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:06:43 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/11 15:09:17 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ant_path(t_ant *ant, int ant_count)
{
	int		i;
	int		j;
	t_path	*path;

	i = 0;
	while (i < ant_count)
	{
		path = ant->path[i];
		j = 0;
		ft_putstr("path ant");
		ft_putnbr(i + 1);
		ft_putendl("");
		while (j < path->size)
		{
			ft_putstr(path->ar[j]->name);
			j++;
		}
		ft_putendl("");
		ft_putstr("pos ");
		ft_putnbr(ant->pos[i]);
		ft_putendl("");
		i++;
	}
}

void	print_path(t_path *path)
{
	int i;

	i = 0;
	while (i < path->size)
	{
		ft_putstr(path->ar[i]->name);
		ft_putstr(" ");
		i++;
	}
}

void	print_resolve(t_resolve *res)
{
	int i;

	i = 0;
	while (i < res->flow_count)
	{
		print_path(res->path_ar[i]);
		ft_putendl("");
		i++;
	}
}

void	print_all_resolves(t_list *resolve)
{
	while (resolve)
	{
		ft_putendl("res:");
		print_resolve(resolve->content);
		resolve = resolve->next;
	}
}

void	path_max_size(t_resolve *res)
{
	int	i;

	i = 0;
	while (i < res->flow_count)
	{
		res->path_ar[i]->max_size = res->path_ar[i]->size;
		i++;
	}
}
