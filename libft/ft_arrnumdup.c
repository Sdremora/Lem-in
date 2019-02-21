/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:34:11 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/11 15:40:23 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arrnum	*ft_arrnumdup(t_arrnum *a)
{
	int			i;
	t_arrnum	*res;

	i = 0;
	res = (t_arrnum*)malloc(sizeof(t_arrnum));
	res->arr = (int*)malloc(a->size * sizeof(int));
	res->size = a->size;
	while (i < a->size)
	{
		res->arr[i] = a->arr[i];
		i++;
	}
	return (res);
}
