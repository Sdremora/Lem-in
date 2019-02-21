/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:26:47 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/29 16:13:02 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	if (!del || !alst)
		return ;
	p = *alst;
	if (p)
	{
		del(p->content, p->content_size);
		if (p->next)
			ft_lstdel(&(p->next), del);
		free(p);
	}
	*alst = NULL;
}
