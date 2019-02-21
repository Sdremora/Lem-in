/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:43:25 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/28 19:07:41 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sub_print(t_list *lst)
{
	ft_putendl((char const *)lst->content);
}

void		ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	ft_lstiter(lst, sub_print);
}
