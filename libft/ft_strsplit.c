/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:44:38 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/11 20:14:42 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sub_cnt(char const *s, char c)
{
	int	i;
	int res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
			res++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (res);
}

static char	*sub_wrd(char const *s, int start, int end)
{
	char	*res;
	int		i;

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

static char	**sub_clean(char **res, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		start;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	if (!s)
		return (NULL);
	res = (char**)malloc((sub_cnt(s, c) + 1) * sizeof(char*));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != start && (res[nb++] = sub_wrd(s, start, i)) == NULL)
			return (sub_clean(res, nb));
	}
	res[nb] = 0;
	return (res);
}
