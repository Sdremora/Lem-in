/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrprnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:45:31 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/14 14:56:51 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrstrprnt(char **arr, int cnt)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	while (i < cnt)
	{
		if (arr[i])
			ft_putendl(arr[i]);
		else
			return ;
		i++;
	}
}
