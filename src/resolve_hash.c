/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:38:31 by sdremora          #+#    #+#             */
/*   Updated: 2019/03/11 12:02:09 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	http://www.amsoftware.narod.ru/algo2.html
*/

static void			part2(unsigned int *hash, long rem, unsigned int i,
						const unsigned char *data)
{
	unsigned char	trail;

	while (rem >= 0)
	{
		trail = *(unsigned char*)data;
		trail += i++;
		*hash ^= trail;
		*hash *= 171717;
		data++;
		rem--;
	}
}

static unsigned int	mafast_hash(char *str, unsigned int len)
{
	unsigned int		hash;
	unsigned int		i;
	unsigned int		k;
	long				rem;
	const unsigned char *data;

	hash = len;
	i = 0;
	rem = len;
	data = (const unsigned char *)str;
	while (rem >= 4)
	{
		k = *(unsigned int*)data;
		k += i++;
		hash ^= k;
		hash *= 171717;
		data += 4;
		rem -= 4;
	}
	part2(&hash, rem, i, data);
	return (hash);
}

static void			room_in_har(t_resolve *resolve, t_room *room)
{
	t_list	*node;
	t_list	*temp;
	int		index;

	if (room->hash == 0)
		room->hash = mafast_hash(room->name, ft_strlen(room->name));
	node = ft_lstput(room, room->hash);
	if (node == NULL)
		error_handle(E_NOMEM);
	index = room->hash % resolve->har_size;
	if (resolve->rooms_har[index] == NULL)
		resolve->rooms_har[index] = node;
	else
	{
		temp = resolve->rooms_har[index];
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

void				hash_fill(t_resolve *resolve)
{
	int		i;
	int		n;
	t_path	*path;

	resolve->har_size = resolve->move_count * 1.5;
	resolve->rooms_har = (t_list **)
					ft_memalloc(sizeof(t_list *) * resolve->har_size);
	if (resolve->rooms_har == NULL)
		error_handle(E_NOMEM);
	i = 0;
	while (i < resolve->flow_count)
	{
		path = resolve->path_ar[i];
		n = 0;
		while (n < path->size)
		{
			room_in_har(resolve, path->ar[n]);
			n++;
		}
		i++;
	}
}
