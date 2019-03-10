
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

int		queue_put(t_queue *queue, void	*content)
{
	t_node	*node;
	t_node	*temp;

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
	void	*data;

	while ((*queue)->size > 0)
	{
		data = queue_get(*queue);
		content_free(data);
	}
	free(*queue);
	*queue = NULL;
}
