
#include "lem_in.h"

int		step_counter(t_resolve *res, int ant_count)
{
	return ((ant_count + res->move_count - 1) / res->flow_count);
}

t_resolve	*get_res(t_list *res)
{
	return (res->content);
}

t_resolve	*get_path(t_list *resolve, int ant_count)
{
	t_list		*solution;
	int			min_step;
	int			temp;

	solution = 0;
	min_step = step_counter(resolve->content, ant_count);
	solution = resolve;
	while (resolve)
	{
		if (min_step > (temp = step_counter(resolve->content, ant_count)))
		{
			min_step = temp;
			solution = resolve;
		}
		resolve = resolve->next;
	}
	if (solution)
		return (solution->content);
	else
		return (0);
}

void	path_reverse(t_path *path)
{
	int		i;
	t_room	*temp;

	i = 0;
	while (i < path->size / 2)
	{
		temp = path->ar[i];
		path->ar[i] = path->ar[path->size - 1 - i];
		path->ar[path->size - 1 - i] = temp;
		i++;
	}
}

void	resolve_reverse(t_resolve *res)
{
	int i;

	i = 0;
	while (i < res->flow_count)
	{
		res->path_ar[i]->max_size = res->path_ar[i]->size;
		path_reverse(res->path_ar[i]);
		i++;
	}
}

t_path	*get_min_path(t_resolve *res)
{
	t_path	*path;
	int		i;
	int		min;

	i = 0;
	path = res->path_ar[i];
	while (++i < res->flow_count)
	{
		if (path->max_size > res->path_ar[i]->max_size)
		{
			path = res->path_ar[i];
		}
	}
	path->max_size += 1;
	return (path);
}

void	ant_cleaner(t_ant *ant)
{
	free(ant->path);
	free(ant->pos);
	free(ant);
}

t_ant	*ant_init(t_resolve *res, int ant_count)
{
	int		i;
	t_ant	*ant;
	t_path	**path;
	int		*pos;

	ant = (t_ant*)malloc(sizeof(t_ant));
	i = 0;
	path = (t_path**)malloc(sizeof(t_path*) * ant_count);
	pos = (int*)malloc(sizeof(int) * ant_count);
	while (i < ant_count)
	{
		path[i] = get_min_path(res);
		pos[i] = 0;
		i++;
	}
	ant->path = path;
	ant->pos = pos;
	return (ant);
}

void	move_ant(t_ant *ant)
{
	return ;
}

void	print_ant_path(t_ant* ant, int ant_count)
{
	int i;
	int j;
	t_path *path;

	i = 0;
	while (i < ant_count)
	{
		path = ant->path[i];
		j = 0;
		printf("path ant  %d \n", i + 1);

		while (j < path->size)
		{
			printf("%s ",path->ar[j]->name);
			j++;
		}
		printf("\n");
		printf("pos %d\n", ant->pos[i]);
		i++;
	}
}

void	print_res(t_resolve *res, int ant_count)
{
	int		i;
	int		j;
	t_ant	*ant;
	int		step;
	int		is_fst;

	is_fst = 1;
	step = step_counter(res, ant_count);
	ant = ant_init(res, ant_count);
	i = 0;
	while (i < step - 1)
	{
		j = 0;
		is_fst = 1;
		while (j < ant_count)
		{
			if (ant->pos[j] + 1 < ant->path[j]->size && ant->path[j]->ar[ant->pos[j] + 1]->is_empty)
			{
				if (is_fst)
				{
					is_fst = 0;
				}
				else
					printf(" ");
				ant->path[j]->ar[ant->pos[j]]->is_empty = 1;	
				if (ant->pos[j] + 1 != ant->path[j]->size - 1)
					ant->path[j]->ar[ant->pos[j] + 1]->is_empty = 0;
				ant->pos[j] += 1;
				printf("L%d-%s", j + 1, ant->path[j]->ar[ant->pos[j]]->name);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	ant_cleaner(ant);
}

char	*solver(t_list *resolve, int ant_count)
{
	char		*result;
	t_list		*solution;
	int			min_step;
	int			temp;
	t_resolve	*res;
	int			i;
	t_room		*room;
	t_path		*path;
	int			k;

	if (resolve)
	{
		res = get_path(resolve, ant_count);
		resolve_reverse(res);
		print_res(res, ant_count);
		return (0);
	}
	result = ft_strdup("L1-2\nL1-3 L2-2\nL1-1 L2-3 L3-2\nL2-1 L3-3\nL3-1\n");
	return (result);
}
