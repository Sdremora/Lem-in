/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:15:02 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/18 18:38:26 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_nb(char c, int base)
{
	int res;

	if (c >= '0' && c <= '9')
		res = c - '0';
	else if (c >= 'a' && c <= 'z')
		res = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		res = c - 'A' + 10;
	else
		return (-1);
	return (res < base ? res : -1);
}

int			ft_atoi_base(char *str, int base)
{
	long long int	res;
	int				sgn;
	int				nb;

	res = 0;
	sgn = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sgn *= -1;
		str++;
	}
	while ((nb = hex_nb(*str, base)) != -1)
	{
		res *= base;
		res += nb;
		if (res < 0)
			return ((sgn + 1) / -2);
		str++;
	}
	return (sgn * res);
}
