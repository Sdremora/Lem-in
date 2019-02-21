/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:10:46 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/29 16:08:38 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	if (!dst && !src)
		return (NULL);
	str1 = (char *)src;
	str2 = (char *)dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}
