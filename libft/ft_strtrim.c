/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:39:21 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/28 16:50:29 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sub_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	sub_getstart(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	sub_getend(char const *s)
{
	int i;

	i = sub_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = sub_getstart(s);
	end = sub_getend(s);
	if (end == -1)
		end = start - 1;
	res = (char*)malloc(end - start + 2);
	if (!res)
		return (NULL);
	i = start;
	while (i < end + 1)
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}
