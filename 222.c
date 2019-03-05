/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   222.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:27:55 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/05 12:50:01 by sdremora         ###   ########.fr       */
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


