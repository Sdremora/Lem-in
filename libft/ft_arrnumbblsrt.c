/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumbblsrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:38:37 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/31 17:49:39 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrnumbblsrt(t_arrnum a)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size - 1 - i)
		{
			if (a.arr[j] > a.arr[j + 1])
			{
				temp = a.arr[j];
				a.arr[j] = a.arr[j + 1];
				a.arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
