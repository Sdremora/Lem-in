/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:25:40 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/23 18:05:10 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sub_len(int nb)
{
	int			res;
	long int	temp;

	temp = nb;
	res = 1;
	if (nb < 0)
	{
		res++;
		temp *= -1;
	}
	while (temp > 9)
	{
		temp /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			sign;
	long int	temp;

	temp = n;
	sign = 0;
	len = sub_len(temp);
	res = (char*)malloc(len + 1);
	if (!res)
		return (NULL);
	if (temp < 0)
	{
		sign = 1;
		res[0] = '-';
		temp *= -1;
	}
	res[len--] = '\0';
	while (len != -1 + sign)
	{
		res[len--] = temp % 10 + '0';
		temp /= 10;
	}
	return (res);
}
