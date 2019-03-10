
#include "lem_in.h"

void	list_half_cleaner(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	list_cleaner(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		free(list->content);
		list = list->next;
		free(temp);
	}
}

void	room_cleaner(t_room *room)
{
	free(room->name);
	list_half_cleaner(room->link_list);
	free(room);
}

void	farm_list_cleaner(t_list *farm)
{
	t_list *temp;

	while (farm)
	{
		temp = farm;
		room_cleaner(farm->content);
		farm = farm->next;
		free(temp);
	}
}

void	farm_cleaner(t_farm *farm)
{
	free(farm->map);
	farm_list_cleaner(farm->room);
	free(farm);
}
