/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:35:45 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/28 20:55:54 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*in;
	char	*out;
	size_t	i;
	char	smbl;

	i = 0;
	smbl = (unsigned char)c;
	in = (char*)src;
	out = (char*)dst;
	while (i < n)
	{
		if (in[i] == smbl)
		{
			out[i] = in[i];
			return ((void *)(dst + i + 1));
		}
		out[i] = in[i];
		i++;
	}
	return (0);
}
