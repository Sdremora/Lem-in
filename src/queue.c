/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:20:00 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/11 12:25:53 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in/queue.h"

t_queue	*queue_new(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	queue->size = 0;
	return (queue);
}

int		queue_put(t_queue *queue, void *content)
{
	t_node	*node;

	node = (t_node *)ft_memalloc(sizeof(t_node));
	if (node == NULL)
		return (-1);
	node->content = content;
	if (queue->size == 0)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->first->prev = node;
		node->next = queue->first;
		queue->first = node;
	}
	queue->size++;
	return (0);
}

void	*queue_get(t_queue *queue)
{
	t_node	*node;
	void	*data;

	if (queue->size == 0)
		return (NULL);
	node = queue->last;
	queue->last = node->prev;
	queue->size--;
	if (queue->size == 0)
		queue->first = NULL;
	data = node->content;
	free(node);
	return (data);
}

void	queue_free(t_queue **queue, void (content_free)(void *content))
{
	if (!*queue)
		return ;
	while ((*queue)->size > 0)
		content_free(queue_get(*queue));
	free(*queue);
	*queue = NULL;
}
