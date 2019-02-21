/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:39:27 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/29 16:08:20 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*in;
	char	*out;
	int		i;

	if (!dst && !src)
		return (NULL);
	in = (char*)src;
	out = (char*)dst;
	if (in > out)
	{
		i = -1;
		while (++i < (int)len)
			out[i] = in[i];
	}
	else
	{
		i = len;
		while (--i > -1)
			out[i] = in[i];
	}
	return (dst);
}
