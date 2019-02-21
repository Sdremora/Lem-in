/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:58:02 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/14 18:03:20 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmalcpy(void *src, size_t size)
{
	char	*res;
	char	*temp;
	size_t	i;

	i = 0;
	res = (char*)malloc(size);
	temp = (char*)src;
	while (i < size)
	{
		res[i] = temp[i];
		i++;
	}
	return (res);
}
