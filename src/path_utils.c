/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:09:01 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/06 16:48:04 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			*path_new(int path_size)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))) ||\
		!(path->ar = (t_room **)ft_memalloc(sizeof(t_room *) * path_size)))
		error_handle(E_NOMEM);
	path->size = 0;
	path->max_size = path_size;
	return (path);
}

t_path	*path_copy(t_path *path)
{
	t_path	*path_copy;
	int		i;

	path_copy = path_new(path->max_size);
	i = 0;
	while (i < path->size)
	{
		path_copy->ar[i] = path->ar[i];
		i++;
	}
	path_copy->size = path->size;
	return (path_copy);
}

void			path_add(t_path *path, t_room *add_room)
{
	if (path->size == path->max_size)
		path_resize(path, path->max_size * 2);
	path->ar[path->size] = add_room;
	path->size++;
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

void			path_free(t_list *path_lst)
{
	t_list		*next_node;
	t_path		*path;

	while (path_lst)
	{
		next_node = path_lst->next;
		path = (t_path *)path_lst->content;
		free(path->ar);
		free(path);
		free(path_lst);
		path_lst = next_node;
	}
}