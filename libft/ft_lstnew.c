/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:42:56 by hharvey           #+#    #+#             */
/*   Updated: 2018/11/24 12:27:31 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*sub_cpy(void const *content, size_t content_size)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char*)content;
	s2 = (char*)malloc(content_size);
	if (!s2)
		return (NULL);
	while (i < content_size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	void	*temp;

	res = (t_list*)malloc(1 * sizeof(t_list));
	if (!res)
		return (NULL);
	if (content && content_size)
	{
		temp = sub_cpy(content, content_size);
		if (!temp)
			return (NULL);
		res->content = temp;
		res->content_size = content_size;
	}
	else
	{
		res->content = NULL;
		res->content_size = 0;
	}
	res->next = NULL;
	return (res);
}
