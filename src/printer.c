/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:07:10 by hharvey           #+#    #+#             */
/*   Updated: 2019/03/11 14:07:12 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printer(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_map(t_farm *farm)
{
	printer(farm->map);
	ft_putendl("");
}
