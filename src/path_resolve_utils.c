/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolve_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:27:55 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/04 11:16:05 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_flow(t_farm *farm)
{
	int	start_flow;
	int	end_flow;

	start_flow = ft_lstlen(farm->start->link_list);
	end_flow = ft_lstlen(farm->end->pre_list);
	return (start_flow < end_flow ? start_flow : end_flow);
}

void		resolve_clean(t_resolve *resolve)
{
	if (resolve)
	{
		free(resolve->path_ar);
		free(resolve);
	}
}

t_resolve	*resolve_ini(int flow_count)
{
	t_resolve	*resolve;

	if (!(resolve = (t_resolve *)malloc(sizeof(t_resolve))) ||\
		!(resolve->path_ar =\
		(t_path **)ft_memalloc(sizeof(t_path *) * flow_count)))
		error_handle(E_NOMEM);
	resolve->flow_count = flow_count;
	resolve->move_count = 0;
	resolve->cur_flow = 0;
	return (resolve);
}

void	resolve_free(t_list *resolve_lst)
{
	t_list		*next_node;
	t_resolve	*resolve;

	while (resolve_lst)
	{
		next_node = resolve_lst->next;
		resolve = (t_resolve *)resolve_lst->content;
		free(resolve->path_ar);
		free(resolve);
		free(resolve_lst);
		resolve_lst = next_node;
	}
}
