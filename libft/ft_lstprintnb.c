/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:00:58 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/27 17:10:15 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sub_print(t_list *lst)
{
	ft_putnbr(*((int *)lst->content));
	ft_putendl("");
}

void		ft_lstprintnb(t_list *lst)
{
	if (!lst)
		return ;
	ft_lstiter(lst, sub_print);
}
