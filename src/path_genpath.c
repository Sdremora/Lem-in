/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_genpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:38:36 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/04 10:38:38 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static t_path	*path_getmin(t_list **path_lst)
{
	t_path	*path;
	t_list	*temp;

	path = (t_path *)(*path_lst)->content;
	temp = *path_lst;
	*path_lst = (*path_lst)->next;
	free(temp);
	return (path);
}

t_path			*path_getnew(t_farm *farm)
{
	static t_list	*path_lst;
	t_list			*temp;
	t_path			*path;

	if (farm == NULL)
	{
		path_logic(NULL, NULL);
		return (NULL);
	}
	if (path_lst)
	{
		path = (t_path *)path_lst->content;
		temp = path_lst;
		path_lst = path_lst->next;
		free(temp);
	}
	else
	{
		path_logic(&path_lst, farm);
		if (!path_lst)
			return (NULL);
		path = path_getmin(&path_lst);
	}
	return (path);
}
