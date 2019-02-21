/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:35:00 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 12:30:40 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	sub_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sub_putchar('-', fd);
		sign = -1;
	}
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10 * sign, fd);
	sub_putchar(n % 10 * sign + '0', fd);
}
