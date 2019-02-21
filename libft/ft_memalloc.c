/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:12:13 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 12:27:51 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*res;
	char	*temp;
	size_t	i;

	i = 0;
	res = malloc(size);
	if (!res)
		return (NULL);
	temp = (char*)res;
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	return (res);
}
