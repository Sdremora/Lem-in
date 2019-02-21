/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myrealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:19:22 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/13 16:23:47 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_myrealloc(void *ptr, size_t size)
{
	char	*res;
	size_t	i;
	char	*temp;

	if (!ptr)
		return (ft_memalloc(size));
	i = 0;
	temp = (char *)ptr;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	while (i < size && temp[i])
	{
		res[i] = temp[i];
		i++;
	}
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	res[size - 1] = 0;
	free(ptr);
	return (res);
}
