/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:32:22 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/15 14:32:47 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	error_handle2(int error_index, char *str_param)
{
	char	str[500];

	ft_bzero(str, 500);
	if (error_index == E_INVLINK)
		ft_strcat(str, "ERROR: invalid link: ");
	else if (error_index == E_DUPTERM)
		ft_strcat(str, "ERROR: found the second command: ");
	else if (error_index == E_DUPROOM)
		ft_strcat(str, "ERROR: found the second identical room: ");
	else if (error_index == E_NOTERM)
		ft_strcat(str, "ERROR: mandatory command not found: ");
	else if (error_index == E_INVINP)
		ft_strcat(str, "ERROR: invalid line in the room part: ");
	ft_strcat(str, str_param);
	ft_putendl(str);
	exit(error_index);
}

void		error_handle(int error_index, ...)
{
	va_list	ap;
	char	str[500];

	va_start(ap, error_index);
	ft_bzero(str, 500);
	if (error_index == E_NOPATH)
		ft_strcat(str, "ERROR: there is no possible way =(");
	else if (error_index == E_BADMAP)
		ft_strcat(str, "ERROR: invalid map");
	else if (error_index == E_NOMEM)
		ft_strcat(str, "ERROR: no mem");
	else if (error_index == E_INVANT)
		ft_strcat(str, "ERROR: invalid number of ants");
	else if (error_index == E_INVLINK || error_index == E_DUPTERM ||
			error_index == E_DUPROOM || error_index == E_NOTERM ||
			error_index == E_INVINP)
		error_handle2(error_index, va_arg(ap, char *));
	else
		ft_strcat(str, "ERROR");
	ft_putendl(str);
	exit(error_index);
}
