/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolve_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:30:02 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/04 10:51:54 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			resolve_check(t_resolve *resolve, t_path *add_path)
{
	int		i;
	int		n;
	int		k;
	t_path	*cur_path;
	t_room	*room;

	i = 0;
	while (i < resolve->cur_flow)
	{
		cur_path = resolve->path_ar[i];
		n = 1;
		while (n < cur_path->size - 1)
		{
			room = cur_path->ar[n];
			k = 1;
			while (k < add_path->size)
			{
				if (room == add_path->ar[k++])
					return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}

static t_resolve	*resolve_builder(t_list *path_lst, int flow)
{
	t_resolve	*resolve;
	t_path		*path;

	resolve = resolve_ini(flow);
	while (resolve->cur_flow < resolve->flow_count)
	{
		if (path_lst == NULL)
		{
			resolve_clean(resolve);
			return (NULL);
		}
		path = (t_path *)path_lst->content;
		if (resolve_check(resolve, path))
		{
			resolve->path_ar[resolve->cur_flow] = path;
			resolve->cur_flow++;
			resolve->move_count += path->size;
		}
		path_lst = path_lst->next;
	}
	return (resolve);
}

static int			resolve_logic(t_resolve *resolve, t_resolve *last_resolve,\
			t_resolve **save_res, int *max_size)
{
	t_resolve *temp;

	if (*save_res == NULL)
	{
		*max_size = resolve->move_count - last_resolve->move_count - 1;
		if (resolve->path_ar[resolve->flow_count - 1]->size > *max_size)
			return (1);
		*save_res = resolve;
	}
	else if (resolve->move_count < (*save_res)->move_count)
	{
		temp = resolve;
		resolve = *save_res;
		*save_res = temp;
	}
	else
		resolve_clean(resolve);
	return (0);
}

static t_resolve	*get_resolve(t_farm *farm, t_resolve *last_res,\
						int flow, t_list **path_lst)
{
	t_path			*path;
	t_resolve		*res;
	t_resolve		*save_res;
	int				max_size;

	res = NULL;
	save_res = NULL;
	max_size = 0;
	while ((path = path_getnew(farm)) != NULL)
	{
		res = NULL;
		path_to_lst(path_lst, path);
		if (save_res != NULL && path->size > max_size)
			break ;
		if ((res = resolve_builder(*path_lst, flow)) == NULL)
			continue ;
		if (flow <= 2 ||\
			resolve_logic(res, last_res, &save_res, &max_size) == 1)
			break ;
	}
	return (res != NULL) ? res : save_res;
}

void				resolve_gen(t_farm *farm, t_list **resolve_lst,\
								t_list **path_lst)
{
	t_resolve	*resolve;
	t_resolve	*last_resolve;
	t_list		*node;
	int			max_flow;
	int			i;

	max_flow = get_flow(farm);
	*resolve_lst = NULL;
	last_resolve = NULL;
	i = 1;
	while (i <= max_flow)
	{
		resolve = get_resolve(farm, last_resolve, i, path_lst);
		if (!resolve)
			break ;
		last_resolve = resolve;
		node = ft_lstput(resolve, sizeof(t_resolve));
		if (node == NULL)
			error_handle(E_NOMEM);
		ft_lstadd(resolve_lst, node);
		i++;
	}
}
