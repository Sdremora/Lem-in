/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:16:20 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/23 14:01:31 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	sub_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(long long int n)
{
	if (n < 0)
	{
		sub_putchar('-');
		n = 0 - n;
	}
	if (n > 9 || n < -9)
		ft_putnbr(n / 10);
	sub_putchar(n % 10 + '0');
}
