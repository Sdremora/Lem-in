/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:52:45 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/22 18:54:12 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	smbl;
	int		i;

	i = 0;
	smbl = (char)c;
	while (s[i])
	{
		if (s[i] == smbl)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == smbl)
		return ((char*)s + i);
	return (0);
}
