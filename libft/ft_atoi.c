/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:33:03 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/28 20:32:12 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	res;
	int				sgn;

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
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		if (res < 0)
			return ((sgn + 1) / -2);
		str++;
	}
	return (sgn * res);
}
