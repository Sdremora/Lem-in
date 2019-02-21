/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:41:59 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/29 20:19:34 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mydel(void *content, size_t size)
{
	size = 0;
	free(content);
}

static t_list	*sub_del(t_list **lst)
{
	if (!lst)
		return (NULL);
	ft_lstdel(lst, mydel);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flist;
	t_list	*temp;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	start = NULL;
	while (lst)
	{
		if (!(temp = f(lst)))
			return (sub_del(&start));
		if (!start)
		{
			start = ft_lstnew(temp->content, temp->content_size);
			flist = start;
		}
		else
		{
			flist->next = ft_lstnew(temp->content, temp->content_size);
			flist = flist->next;
		}
		lst = lst->next;
	}
	return (start);
}
