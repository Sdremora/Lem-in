/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:04:27 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/11 12:24:03 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "libft.h"

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_queue
{
	t_node	*first;
	t_node	*last;
	size_t	size;
}				t_queue;

t_queue			*queue_new(void);
int				queue_put(t_queue *queue, void	*content);
void			*queue_get(t_queue *queue);
void			queue_free(t_queue **queue, void (content_free)(void *content));

#endif
