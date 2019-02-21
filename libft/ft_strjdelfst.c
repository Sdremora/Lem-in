/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjdelfst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:48:56 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/01 16:57:16 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjdelfst(char *str, const char *str2)
{
	char *res;

	if (str)
	{
		res = ft_strjoin(str, str2);
		free(str);
	}
	else
		return (ft_strdup(str2));
	return (res);
}
