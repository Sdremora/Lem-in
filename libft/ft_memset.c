/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:41:53 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 12:30:08 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*res;
	size_t	i;
	char	smbl;

	i = 0;
	smbl = (unsigned char)c;
	res = (char *)b;
	while (i < len)
	{
		res[i] = smbl;
		i++;
	}
	return (b);
}
