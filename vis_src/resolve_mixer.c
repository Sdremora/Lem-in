/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_mixer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:08:29 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/18 16:11:45 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	resolve_check(t_resolve *resolve, t_path *path)
{
	int		i;
	int		n;
	t_list	*node;
	t_room	*room;

	i = 1;
	while (i < path->size - 1)
	{
		room = path->ar[i];
		if (room->hash != 0)
		{
			n = room->hash % resolve->har_size;
			node = resolve->rooms_har[n];
			while (node)
			{
				if (node->content_size == room->hash)
					return (0);
				node = node->next;
			}
		}
		i++;
	}
	return (1);
}

static void	resolve_to_state(t_state *state, t_resolve *resolve, int flow)
{
	t_list	*node;
	t_list	*prev;
	t_list	*cur;

	node = ft_lstput(resolve, resolve->move_count);
	if (!node)
		error_handle(E_NOMEM);
	prev = NULL;
	cur = state->res_ar[flow];
	while (cur && cur->content_size < node->content_size)
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL)
	{
		node->next = state->res_ar[flow];
		state->res_ar[flow] = node;
	}
	else
	{
		prev->next = node;
		node->next = cur;
	}
}

static void	resolve_merge(t_state *state, t_resolve *resolve,
						t_path *path, int flow)
{
	t_resolve	*new_res;
	int			i;

	if (flow > state->max_flow && flow < state->target_flow)
		state->max_flow = flow;
	new_res = resolve_ini(flow + 1);
	i = 0;
	while (i < resolve->flow_count)
	{
		new_res->path_ar[i] = resolve->path_ar[i];
		i++;
	}
	new_res->path_ar[i] = path;
	new_res->move_count = resolve->move_count + path->size;
	hash_fill(new_res);
	resolve_to_state(state, new_res, flow);
}

static void	resolve_addone(t_state *state, t_path *path)
{
	t_resolve	*new_res;
	t_list		*node;
	t_list		*temp;

	new_res = resolve_ini(1);
	new_res->path_ar[0] = path;
	new_res->move_count = path->size;
	hash_fill(new_res);
	node = ft_lstput(new_res, path->size);
	if (!node)
		error_handle(E_NOMEM);
	if (state->res_ar[0] == NULL)
	{
		state->res_ar[0] = node;
		state->last_one = node;
	}
	else
	{
		temp = state->last_one;
		state->last_one = node;
		temp->next = node;
	}
	state->res_count++;
}

void		resolve_mixer(t_state *state, t_path *path)
{
	int			flow;
	t_list		*res_node;
	t_resolve	*resolve;
	int			count;

	flow = state->max_flow;
	while (flow >= 0 && flow > state->cur_flow - state->deep_count)
	{
		res_node = state->res_ar[flow];
		count = 0;
		while (res_node && count < 50)
		{
			resolve = (t_resolve *)res_node->content;
			if (resolve_check(resolve, path))
			{
				resolve_merge(state, resolve, path, flow + 1);
				state->res_count++;
			}
			res_node = res_node->next;
			count++;
		}
		flow--;
	}
	resolve_addone(state, path);
}
