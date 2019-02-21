/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:49:20 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/13 13:59:32 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *src, size_t src_size, size_t new_size)
{
	void	*res;

	res = ft_memalloc(new_size);
	if (src)
	{
		res = ft_memcpy(res, src, src_size);
		free(src);
	}
	return (res);
}
