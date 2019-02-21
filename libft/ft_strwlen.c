/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:03:07 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/25 17:57:39 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>

size_t	ft_strwlen(const wchar_t *s)
{
	size_t	i;
	wchar_t	c;

	i = 0;
	while (*s)
	{
		c = *s;
		if (c < 127)
			i++;
		else if (c < 2048)
			i += 2;
		else if (c < 65536)
			i += 3;
		else
			i += 4;
		s++;
	}
	return (i);
}
