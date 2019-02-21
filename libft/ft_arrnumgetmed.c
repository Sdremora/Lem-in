/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumgetmed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:50:49 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/06 16:52:57 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrnumgetmed(t_arrnum a, int start, int end)
{
	int count;
	int i;
	int j;

	i = start;
	while (i < end && i < a.size)
	{
		j = start;
		count = 0;
		while (j < a.size && j < end)
		{
			if (a.arr[j] < a.arr[i] && i != j)
			{
				count++;
			}
			j++;
		}
		if (count == (end - start) / 2)
			return (a.arr[i]);
		i++;
	}
	return (-1);
}
