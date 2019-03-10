/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolve_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:27:55 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/10 15:39:18 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_flow(t_farm *farm)
{
	int		max_flow;
	int		start_flow;
	int		end_flow;

	start_flow = ft_lstlen(farm->start->link_list);
	end_flow = ft_lstlen(farm->end->link_list);
	max_flow = start_flow < end_flow ? start_flow : end_flow;
	max_flow = max_flow < farm->ant_count ? max_flow : farm->ant_count;
	return (max_flow);
}

t_state		*state_ini(t_farm *farm)
{
	t_state	*state;
	int		target_flow;

	target_flow = get_flow(farm);
	if (!(state = (t_state *)malloc(sizeof(t_state))) ||\
		!(state->res_ar =\
		(t_list **)ft_memalloc(sizeof(t_list *) * target_flow)))
		error_handle(E_NOMEM);
	state->last_one = NULL;
	state->cur_flow = 0;
	state->max_flow = 0;
	state->target_flow = target_flow;
	state->res_count = 0;
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
	resolve->rooms_har = NULL;
	resolve->har_size = 0;
	return (resolve);
}

