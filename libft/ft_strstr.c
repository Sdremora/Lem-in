/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:11:51 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 13:41:05 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *stack, const char *find)
{
	int i;
	int j;

	i = 0;
	if (!find[0])
		return ((char*)stack);
	while (stack[i])
	{
		j = 0;
		if (stack[i] == find[j] || !find[j])
		{
			while (find[j] == stack[i + j] && stack[i + j])
				j++;
			if (!find[j])
				return ((char*)stack + i);
		}
		i++;
	}
	return (0);
}
