/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:21:44 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/31 17:44:02 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrnumprint(t_arrnum arrnum)
{
	int	i;

	i = 0;
	if (arrnum.arr == 0)
		return ;
	while (i < arrnum.size)
	{
		ft_putnbr(arrnum.arr[i]);
		if (i != arrnum.size - 1)
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}
