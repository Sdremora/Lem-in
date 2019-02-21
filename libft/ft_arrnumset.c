/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:52:28 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/26 20:53:43 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrnumset(t_arrnum *arrnum, int *arr, int size)
{
	arrnum->arr = arr;
	arrnum->size = size;
}
