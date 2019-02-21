/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:24:27 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/26 16:30:00 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sub_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len1 = sub_strlen(s1);
	len2 = sub_strlen(s2);
	len = len1 + len2;
	res = (char*)malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		if (i < len1)
			res[i] = s1[i];
		else
			res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
