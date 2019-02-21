/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:21:55 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/15 16:26:40 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelchr(char *str)
{
	int len;

	len = ft_strlen(str);
	str = ft_memmove(str, str + 1, len - 1);
	str[len - 1] = '\0';
	return (str);
}
