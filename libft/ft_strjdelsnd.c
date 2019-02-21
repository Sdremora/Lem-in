/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjdelsnd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:32:54 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 14:56:11 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjdelsnd(const char *str, char *str2)
{
	char *res;

	if (str2)
	{
		res = ft_strjoin(str, str2);
		free(str2);
	}
	else
		return (ft_strdup(str));
	return (res);
}
