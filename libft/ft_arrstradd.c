/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstradd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:34:47 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/18 20:08:51 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrstradd(char **input, char *str)
{
	int		len;
	char	**temp;
	int		i;

	i = 0;
	len = ft_arrstrlen(input);
	temp = (char**)malloc(sizeof(char*) * (len + 2));
	while (i < len + 1)
	{
		temp[i] = input[i];
		i++;
	}
	temp[i] = str;
	temp[i + 1] = 0;
	free(input);
	return (temp);
}
