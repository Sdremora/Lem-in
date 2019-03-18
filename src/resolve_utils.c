/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:27:55 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/18 16:05:37 by sdremora         ###   ########.fr       */
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
		(t_list **)ft_memalloc(sizeof(t_list *) * (target_flow + 1))))
		error_handle(E_NOMEM);
	state->last_one = NULL;
	state->cur_flow = 0;
	state->max_flow = 0;
	state->target_flow = target_flow;
	state->res_count = 0;
	state->deep_count = 3;
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

void		resolve_free(t_resolve *resolve)
{
	t_list		*node;
	t_list		*next;
	int			i;

	if (resolve->flow_count == 1)
	{
		free(resolve->path_ar[0]->ar);
		free(resolve->path_ar[0]);
	}
	i = 0;
	while (i < resolve->har_size)
	{
		node = resolve->rooms_har[i];
		while (node)
		{
			next = node->next;
			free(node);
			node = next;
		}
		i++;
	}
	free(resolve->path_ar);
	free(resolve->rooms_har);
	free(resolve);
}

void		state_free(t_state *state)
{
	t_list		*node;
	t_list		*next;
	int			i;

	i = 0;
	while (i <= state->max_flow)
	{
		node = state->res_ar[i];
		while (node)
		{
			next = node->next;
			resolve_free((t_resolve *)node->content);
			free(node);
			node = next;
		}
		i++;
	}
	free(state->res_ar);
	free(state);
}
