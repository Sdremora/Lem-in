/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:43:38 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/23 14:53:55 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_itoa_len(long long int nb, int base)
{
	int res;

	if (!nb)
		return (1);
	if (nb < 0)
		res = 1;
	else
		res = 0;
	while (nb)
	{
		nb /= base;
		res++;
	}
	return (res);
}

char		*ft_itoa_base(long long int nb, int base, int isbig)
{
	int			len;
	char		*res;
	int			i;
	static char	base_ar[33] = "";

	if (!base_ar[0])
		ft_strcpy(base_ar, "0123456789abcdef0123456789ABCDEF");
	i = 1;
	len = ft_get_itoa_len(nb, base);
	if (!(res = ft_memalloc(len + 1)))
		return (0);
	if (nb < 0)
		res[0] = '-';
	while (nb / base)
	{
		res[len - i] = base_ar[ft_abs(nb % base) + isbig * 16];
		nb /= base;
		i++;
	}
	res[len - i] = base_ar[ft_abs(nb % base) + isbig * 16];
	return (res);
}
