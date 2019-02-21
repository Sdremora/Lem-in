/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:58:47 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/23 13:53:22 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long long int nb, int base, int isbig)
{
	int			i;
	static char	base_ar[33] = "";

	if (!base_ar[0])
		ft_strcpy(base_ar, "0123456789abcdef0123456789ABCDEF");
	i = 1;
	if (nb / base)
		ft_putnbr_base(nb / base, base, isbig);
	ft_putchar(base_ar[(nb % base) + isbig * 16]);
}
