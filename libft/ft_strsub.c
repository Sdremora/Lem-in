/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:17:03 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/26 16:29:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = start;
	res = (char*)malloc(len + 1);
	if (!res)
		return (NULL);
	while (i - start < len)
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}
