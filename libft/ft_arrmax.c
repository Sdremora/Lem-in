/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:44:46 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/05 20:02:16 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrposmax(int *a, int size)
{
	int i;
	int max;
	int res;

	i = 0;
	max = a[0];
	res = 0;
	while (i < size)
	{
		if (a[i] > max)
		{
			max = a[i];
			res = i;
		}
		i++;
	}
	return (res);
}

int	ft_arrposmin(int *a, int size)
{
	int i;
	int min;
	int res;

	i = 0;
	min = a[0];
	res = 0;
	while (i < size)
	{
		if (a[i] < min)
		{
			min = a[i];
			res = i;
		}
		i++;
	}
	return (res);
}
