/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:22:16 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/23 18:18:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		id_in_lst(t_list *lst, int id)
{
	while (lst)
	{
		if (ft_lstgetnb(lst) == id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	add_res(t_list *res, t_list *path, int nb)
{
	t_resolve	*temp;

	while (res)
	{
		res = res->next;
	}
	temp = (t_resolve*)malloc(sizeof(t_resolve));
	temp->nb = nb;
	temp->path = ft_ltan(path);
	res->content = temp;
	res->content_size = sizeof(*temp);
}

void	way_finder(t_farm *farm, t_list *res, int start, int prev)
{
	static t_list	*path = 0;
	int				i;
	t_list			*temp;
	static int		nb = 0;
	int				next;
	t_list			*back;


	if (start == farm->size - 1)
	{
		ft_lstprintnb(path);
//		add_res(res, path, nb);
		nb++;
		return ;
	}
	i = 0;
	while (i < farm->room[start]->conn->size)
	{
		next = farm->room[start]->conn->arr[i];
//		printf("%d\n", i);

		if (next != prev && !id_in_lst(path, next))
		{
			temp = ft_lstnew(&next, sizeof(next));
			ft_lstadd(&path, temp);
			way_finder(farm, temp, next, start);
		}
		else
		{
			i++;
			continue ;
		}
		if (path)
		{
			back = path;
			path = path->next;
			free(back->content);
			free(back);
		}
		
		i++;
	}	
}
