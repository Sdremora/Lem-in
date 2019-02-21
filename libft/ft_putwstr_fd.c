/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:06:49 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/25 17:55:31 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr_fd(const wchar_t *s, int fd)
{
	int res;

	res = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		res += ft_putwchar_fd(*s, fd);
		s++;
	}
	return (res);
}
