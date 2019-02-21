/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:20:23 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 13:40:09 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *stack, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!find[0])
		return ((char*)stack);
	while (stack[i] && i < len)
	{
		j = 0;
		if (stack[i] == find[j] || !find[j])
		{
			while (find[j] == stack[i + j] && i + j < len && find[j])
				j++;
			if (!find[j])
				return ((char*)stack + i);
		}
		i++;
	}
	if (!*find)
		return ((char*)stack);
	return (0);
}
