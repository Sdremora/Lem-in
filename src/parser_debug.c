#include "lem_in.h"

void	room_printer(t_room *room)
{
	t_list *lst;

	ft_putendl(room->name);
	lst = room->link_list;
	while (lst)
	{
		ft_putstr(((t_room*)lst->content)->name);
		ft_putstr(" ");
		lst = lst->next;
	}
	ft_putendl("");
}

void	farm_printer(t_farm *res)
{
	t_list *lst;

	lst = res->room;
	while (lst)
	{
		room_printer(lst->content);
		lst = lst->next;
	}
}