/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:47:27 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/20 19:51:22 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t maxlen)
{
	int		len;
	char	*res;
	int		i;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	len = ft_min(len, maxlen);
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
