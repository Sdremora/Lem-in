/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:02:13 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/14 11:03:12 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		resolve_isbest(t_state *state)
{
	int			cur_flow;
	t_resolve	*resolve;
	t_resolve	*prev_resolve;
	int			max_size;
	t_path		*path;

	cur_flow = state->cur_flow;
	if (state->res_ar[cur_flow] == NULL)
		return (0);
	if (cur_flow < 2)
		return (1);
	resolve = (t_resolve *)state->res_ar[cur_flow]->content;
	prev_resolve = (t_resolve *)state->res_ar[cur_flow - 1]->content;
	path = ((t_resolve *)state->last_one->content)->path_ar[0];
	max_size = resolve->move_count - prev_resolve->move_count;
	if (path->size < max_size)
		return (0);
	return (1);
}

static void		state_fill(t_state *state, t_farm *farm)
{
	t_path	*path;

	while (state->cur_flow < state->target_flow)
	{
		if (resolve_isbest(state))
		{
			state->cur_flow++;
			if (state->cur_flow > 7)
				state->deep_count = 2;
			continue;
		}
		path = path_getnew(farm);
		if ((path && state->cur_flow > 0 &&
			step_counter(state->res_ar[state->cur_flow - 1]->content,
			farm->ant_count) < path->size) ||
			state->res_count > 200000)
		{
			path_free(path);
			break ;
		}
		if (!path)
			break ;
		resolve_mixer(state, path);
	}
}

t_list			*resolve_finder(t_farm *farm)
{
	static t_state	*state;
	t_resolve		*resolve;
	t_list			*result_lst;
	t_list			*node;
	int				i;

	result_lst = NULL;
	if (farm == NULL)
		state_free(state);
	else
	{
		state = state_ini(farm);
		state_fill(state, farm);
		i = 0;
		while (i < state->cur_flow)
		{
			resolve = (t_resolve *)state->res_ar[i]->content;
			node = ft_lstput(resolve, sizeof(t_resolve));
			if (!node)
				error_handle(E_NOMEM);
			ft_lstadd(&result_lst, node);
			i++;
		}
	}
	return (result_lst);
}
