/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:00:58 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/11 14:03:49 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sub_print(t_list *lst)
{
	ft_putnbr(*((int *)lst->content));
	ft_putchar(' ');
}

void		ft_lstprintnb(t_list *lst)
{
	if (!lst)
		return ;
	ft_lstiter(lst, sub_print);
	ft_putendl("");
}
