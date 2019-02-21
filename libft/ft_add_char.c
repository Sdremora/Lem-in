/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:20:43 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/15 16:02:01 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_char(char *str, char c)
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
	str[len] = c;
	return (str);
}
