/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 10:19:27 by sdremora          #+#    #+#             */
/*   Updated: 2019/02/24 10:25:07 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Содаем новый элемент списка и кидаем в него контент
*/

t_list	*ft_lstput(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = (void *)content;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
