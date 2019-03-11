/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_print_res.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:06:55 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/11 15:09:13 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*get_min_path(t_resolve *res)
{
	t_path	*path;
	int		i;

	i = 0;
	path = res->path_ar[i];
	while (++i < res->flow_count)
	{
		if (path->max_size > res->path_ar[i]->max_size)
		{
			path = res->path_ar[i];
		}
	}
	path->max_size += 1;
	return (path);
}

void	ant_cleaner(t_ant *ant)
{
	free(ant->path);
	free(ant->pos);
	free(ant);
}

t_ant	*ant_init(t_resolve *res, int ant_count)
{
	int		i;
	t_ant	*ant;
	t_path	**path;
	int		*pos;

	ant = (t_ant*)malloc(sizeof(t_ant));
	i = 0;
	path = (t_path**)malloc(sizeof(t_path*) * ant_count);
	pos = (int*)malloc(sizeof(int) * ant_count);
	while (i < ant_count)
	{
		path[i] = get_min_path(res);
		pos[i] = 0;
		i++;
	}
	ant->path = path;
	ant->pos = pos;
	return (ant);
}

void	print_ant_move(int j, t_ant *ant, int *is_fst)
{
	if (ant->pos[j] + 1 < ant->path[j]->size
			&& ant->path[j]->ar[ant->pos[j] + 1]->is_empty)
	{
		if (*is_fst)
			*is_fst = 0;
		else
			ft_putstr(" ");
		ant->path[j]->ar[ant->pos[j]]->is_empty = 1;
		if (ant->pos[j] + 1 != ant->path[j]->size - 1)
			ant->path[j]->ar[ant->pos[j] + 1]->is_empty = 0;
		ant->pos[j] += 1;
		ft_putstr("L");
		ft_putnbr(j + 1);
		ft_putstr("-");
		ft_putstr(ant->path[j]->ar[ant->pos[j]]->name);
	}
}

void	print_res(t_resolve *res, int ant_count)
{
	int		i;
	int		j;
	t_ant	*ant;
	int		is_fst;

	path_max_size(res);
	ant = ant_init(res, ant_count);
	i = 0;
	while (1)
	{
		j = 0;
		is_fst = 1;
		while (j < ant_count)
		{
			print_ant_move(j, ant, &is_fst);
			j++;
		}
		ft_putendl("");
		if (ant->pos[ant_count - 1] == ant->path[ant_count - 1]->size - 1)
			break ;
		i++;
	}
	ant_cleaner(ant);
}
