
#include "lem_in.h"

int		lst_is_new(t_list *farm, t_list *lst, t_list *clist)
{
	while (farm)
	{
		if (get_room(farm) == get_room(clist))
			return (1);
		if (get_room(farm) == get_room(lst))
			return (0);
		farm = farm->next;
	}
	return (42);
}

void	print_connection(t_list *lst, t_farm *farm)
{
	t_list	*clist;

	while (lst)
	{
		clist = ((t_room*)lst->content)->link_list;
		while (clist)
		{
			if (lst_is_new(farm->room, lst, clist))
			{
				ft_putstr(get_room(lst)->name);
				ft_putstr("-");
				ft_putendl(get_room(clist)->name);
			}
			clist = clist->next;
		}
		lst = lst->next;
	}
	ft_putendl("");
}

void	print_map(t_farm *farm)
{
	t_list	*lst;
	t_list	*clist;

	ft_putnbr(farm->ant_count);
	ft_putendl("");
	lst = farm->room;
	while (lst)
	{
		if (((t_room*)lst->content)->type == 1)
			ft_putendl("##start");
		else if (((t_room*)lst->content)->type == 2)
			ft_putendl("##end");
		ft_putstr(((t_room*)lst->content)->name);
		ft_putstr(" ");
		ft_putnbr(((t_room*)lst->content)->x);
		ft_putstr(" ");
		ft_putnbr(((t_room*)lst->content)->y);
		ft_putendl("");
		lst = lst->next;
	}
	print_connection(farm->room, farm);
}

void	printer(char *str)
{
	write(1, str, ft_strlen(str));
}
