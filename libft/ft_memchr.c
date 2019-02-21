/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:46:03 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 12:28:44 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	smbl;
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	smbl = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == smbl)
			return (str + i);
		i++;
	}
	return (0);
}
