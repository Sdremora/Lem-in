/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:12:21 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/20 18:30:09 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ltas(t_list *lst)
{
	char	**res;
	int		len;
	int		i;
	t_list	*temp;

	i = 0;
	len = ft_lstlen(lst);
	res = (char**)malloc(sizeof(char*) * (len + 1));
	while (i < len)
	{
		temp = lst;
		res[i] = lst->content;
		lst = lst->next;
		free(temp);
		i++;
	}
	res[i] = 0;
	return (res);
}
