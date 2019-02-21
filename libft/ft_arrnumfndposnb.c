/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumfndposnb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:47:50 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/11 15:58:26 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrnumfndposnb(t_arrnum *a, int nb)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		if (nb == a->arr[i])
			return (i);
		i++;
	}
	return (-1);
}
