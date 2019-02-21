/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:54:11 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/17 19:58:09 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewchr(size_t size, int c)
{
	char	*res;
	size_t	i;

	if (size == (size_t)-1)
		return (NULL);
	i = 0;
	res = (char*)malloc(size + 1);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = c;
		i++;
	}
	res[i] = '\0';
	return (res);
}
