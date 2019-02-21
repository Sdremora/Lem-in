/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:35:51 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/15 16:01:22 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addr_char(char *str, char c)
{
	int len;

	if (!str)
	{
		str = (char*)malloc(2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	len = ft_strlen(str);
	str = ft_myrealloc(str, len + 2);
	ft_memmove(str + 1, str, len + 1);
	str[0] = c;
	return (str);
}
