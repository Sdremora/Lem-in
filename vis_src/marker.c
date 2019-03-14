
#include "lem_in.h"

void	mark_start(t_farm *farm)
{
	t_queue	*qu;
	t_room	*room;
	t_room	*next_room;
	t_list	*temp;

	qu = queue_new();
	farm->start->start_count = 0;
	queue_put(qu, farm->start);
	while (qu->size > 0)
	{
		room = (t_room *)queue_get(qu);
		temp = room->link_list;
		while (temp)
		{
			next_room = (t_room *)temp->content;
			if (next_room->start_count == -1 && next_room->type != R_END)
			{
				next_room->start_count = room->start_count + 1;
				queue_put(qu, next_room);
			}
			temp = temp->next;
		}
	}
	free(qu);
}

void	mark_end(t_farm *farm)
{
	t_queue	*qu;
	t_room	*room;
	t_room	*next_room;
	t_list	*temp;

	qu = queue_new();
	farm->end->end_count = 0;
	queue_put(qu, farm->end);
	while (qu->size > 0)
	{
		room = (t_room *)queue_get(qu);
		temp = room->link_list;
		while (temp)
		{
			next_room = (t_room *)temp->content;
			if (next_room->end_count == -1 && next_room->type != R_START)
			{
				next_room->end_count = room->end_count + 1;
				queue_put(qu, next_room);
			}
			temp = temp->next;
		}
	}
	free(qu);
}

void	marker(t_farm *farm)
{

	mark_start(farm);
	mark_end(farm);
}