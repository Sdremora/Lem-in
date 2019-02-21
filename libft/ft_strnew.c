/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:25:37 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/30 12:45:27 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	if (size == (size_t)-1)
		return (NULL);
	i = 0;
	res = (char*)malloc(size + 1);
	if (!res)
		return (NULL);
	while (i < size + 1)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
