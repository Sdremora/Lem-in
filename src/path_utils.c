/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:09:01 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/04 10:39:22 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*path_get_copy(t_path *path)
{
	t_path	*path_copy;
	int		i;

	path_copy = path_ini(path->max_size);
	i = 0;
	while (i < path->size)
	{
		path_copy->ar[i] = path->ar[i];
		i++;
	}
	path_copy->size = path->size;
	return (path_copy);
}

void			path_add(t_list **lst, t_path *orig_path, t_room *add_room)
{
	t_path	*path_copy;

	path_copy = path_get_copy(orig_path);
	if (path_copy->size == path_copy->max_size)
		path_resize(path_copy, path_copy->max_size * 2);
	path_copy->ar[path_copy->size] = add_room;
	path_copy->size++;
	path_to_lst(lst, path_copy);
}

t_path			*path_ini(int path_size)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))) ||\
		!(path->ar = (t_room **)ft_memalloc(sizeof(t_room *) * path_size)))
		error_handle(E_NOMEM);
	path->size = 0;
	path->max_size = path_size;
	return (path);
}

void			path_to_lst(t_list **lst, t_path *path)
{
	t_list	*path_node;

	path_node = ft_lstput(path, sizeof(t_path));
	if (!path_node)
		error_handle(E_NOMEM);
	ft_lstadd(lst, path_node);
}

void			path_resize(t_path *path, int new_ar_size)
{
	t_room	**temp;
	int		i;

	if (new_ar_size <= path->max_size)
		return ;
	temp = (t_room **)ft_memalloc(sizeof(t_room *) * new_ar_size);
	if (!temp)
		error_handle(E_NOMEM);
	i = 0;
	while (i < path->size)
	{
		temp[i] = path->ar[i];
		i++;
	}
	free(path->ar);
	path->ar = temp;
	path->max_size = new_ar_size;
}
