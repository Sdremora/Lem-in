/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolve_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:27:55 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/05 14:16:38 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_state	*state_ini(t_farm *farm)
{
	t_state	*state;
	int		max_flow;
	int		start_flow;
	int		end_flow;

	start_flow = ft_lstlen(farm->start->link_list);
	end_flow = ft_lstlen(farm->end->pre_list);
	max_flow = start_flow < end_flow ? start_flow : end_flow;
	if (!(state = (t_state *)malloc(sizeof(t_state))) ||\
		!(state->res_ar = (t_list **)ft_memalloc(sizeof(t_list *) * max_flow)))
		error_handle(E_NOMEM);
	state->cur_flow = 0;
	state->max_flow = 0;
	state->target_flow = max_flow;
	state->last_one = NULL;
	return (state);
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
	return (resolve);
}

void		resolve_free(t_list *resolve_lst)
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