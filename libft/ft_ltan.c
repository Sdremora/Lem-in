/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:52:56 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/23 17:33:21 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arrnum	*ft_ltan(t_list *lst)
{
	t_arrnum	*res;
	int			len;
	int			*arr;
	int			i;
	t_list		*temp;

	res = (t_arrnum*)malloc(sizeof(t_arrnum));
	len = ft_lstlen(lst);
	res->size = len;
	arr = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_lstgetnb(lst);
		temp = lst;
		lst = lst->next;
		i++;
	}
	res->arr = arr;
	return (res);
}
