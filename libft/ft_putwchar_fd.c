/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:24:22 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/25 17:34:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwchar_fd(wchar_t c, int fd)
{
	char data[4];

	if (c < 127)
		return (write(fd, &c, 1));
	else if (c < 2048)
	{
		data[0] = c >> 6 | 0xc0;
		data[1] = (c & 0x3F) | 0x80;
		return (write(fd, data, 2));
	}
	else if (c < 65536)
	{
		data[0] = c >> 12 | 0xE0;
		data[1] = (c >> 6 & 0x3F) | 0x80;
		data[2] = (c & 0x3F) | 0x80;
		return (write(fd, data, 3));
	}
	else
	{
		data[0] = c >> 18 | 0xF0;
		data[1] = (c >> 12 & 0x3F) | 0x80;
		data[2] = (c >> 6 & 0x3F) | 0x80;
		data[3] = (c & 0x3F) | 0x80;
		return (write(fd, data, 4));
	}
}
