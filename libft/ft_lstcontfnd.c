/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontfnd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:42:34 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/20 18:49:24 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcontfnd(t_list *lst, t_list req, int (*f)())
{
	while (lst)
	{
		if (f(lst->content, req.content) == 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}
