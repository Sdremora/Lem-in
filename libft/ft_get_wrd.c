/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:05:04 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/29 18:20:40 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_get_wrd(char const *s, int start, int end)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = start;
	res = (char*)malloc(end - start + 1);
	if (!res)
		return (NULL);
	while (i < end)
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}
