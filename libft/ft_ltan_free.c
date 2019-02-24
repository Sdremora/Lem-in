/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltan_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:29:25 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/23 17:30:10 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arrnum	*ft_ltan_free(t_list *lst)
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
		ft_lstdelone(&temp, ft_lstdelfun);
		i++;
	}
	res->arr = arr;
	return (res);
}
