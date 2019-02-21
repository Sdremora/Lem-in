/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:03:20 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/13 16:07:44 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreejoin(char *str1, char *str2)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (res);
}
