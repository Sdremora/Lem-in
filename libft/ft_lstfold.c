/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:18:35 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/30 12:53:07 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfold(t_list *lst, t_list *(*f)(t_list *list1, t_list *list2))
{
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
		res = f(lst, lst->next);
	else
		return (lst);
	lst = lst->next;
	while (lst->next)
	{
		lst = lst->next;
		res = f(res, lst);
	}
	return (res);
}
