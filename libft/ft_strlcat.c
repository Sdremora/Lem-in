/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:02:06 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/27 14:45:00 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	sub_strlen(const char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res++;
		str++;
	}
	return (res);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i + j < size)
		i++;
	if (i + j + 1 >= size)
		return (i + sub_strlen(src));
	while (j + i + 1 < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + sub_strlen(src));
}
