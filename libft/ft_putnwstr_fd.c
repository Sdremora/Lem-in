/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:16:58 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/25 19:00:55 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnwstr_fd(wchar_t const *s, int n, int fd)
{
	int res;

	res = 0;
	if (!s)
		return (-1);
	while (*s && res + ft_wcharlen(*s) <= n)
	{
		res += ft_putwchar_fd(*s, fd);
		s++;
	}
	return (res);
}
