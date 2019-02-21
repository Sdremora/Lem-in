/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:19:42 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/29 16:13:39 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;

	if (!del || !alst)
		return ;
	p = *alst;
	if (p)
	{
		del(p->content, p->content_size);
		free(p);
	}
	*alst = NULL;
}
