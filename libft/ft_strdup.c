/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:38:27 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/16 16:01:03 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*res;
	int		i;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	res = (char*)malloc(len + 1);
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
