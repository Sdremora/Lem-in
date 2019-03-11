/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:05:50 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/11 14:05:53 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			step_counter(t_resolve *res, int ant_count)
{
	return ((ant_count + res->move_count - 1) / res->flow_count);
}

t_resolve	*get_path(t_list *resolve, int ant_count)
{
	t_list		*solution;
	int			min_step;
	int			temp;

	solution = 0;
	min_step = step_counter(resolve->content, ant_count);
	solution = resolve;
	while (resolve)
	{
		if (min_step > (temp = step_counter(resolve->content, ant_count)))
		{
			min_step = temp;
			solution = resolve;
		}
		resolve = resolve->next;
	}
	if (solution)
		return (solution->content);
	else
		return (0);
}

void		path_reverse(t_path *path)
{
	int		i;
	t_room	*temp;

	i = 0;
	while (i < path->size / 2)
	{
		temp = path->ar[i];
		path->ar[i] = path->ar[path->size - 1 - i];
		path->ar[path->size - 1 - i] = temp;
		i++;
	}
}

void		resolve_reverse(t_resolve *res)
{
	int i;

	i = 0;
	while (i < res->flow_count)
	{
		res->path_ar[i]->max_size = res->path_ar[i]->size;
		path_reverse(res->path_ar[i]);
		i++;
	}
}

void		solver(t_list *resolve, int ant_count)
{
	t_resolve	*res;

	if (resolve)
	{
		res = get_path(resolve, ant_count);
		print_res(res, ant_count);
	}
	else
	{
		ft_error();
	}
}
