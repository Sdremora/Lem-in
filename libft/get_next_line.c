/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:22:51 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/13 11:05:41 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_line(char **line, char *buf)
{
	char	*pos;
	int		end;
	int		res;
	int		len;

	res = 0;
	if ((pos = ft_strchr(buf, '\n')))
	{
		end = pos - buf;
		res = 1;
	}
	else
		end = ft_strlen(buf);
	if (end > 0)
	{
		len = ft_strlen(*line) + end + 1;
		*line = (char *)ft_myrealloc(*line, len);
		if (!*line)
			return (-1);
		ft_strlcat(*line, buf, len);
	}
	res == 1 ? ft_memmove(buf, buf + end + 1, BUFF_SIZE - end) : ft_strclr(buf);
	return (res);
}

static char	*get_buf(t_fdlist **fdlist, int fd)
{
	if (!*fdlist)
	{
		*fdlist = (t_fdlist *)malloc(sizeof(t_fdlist));
		(*fdlist)->fd = fd;
		(*fdlist)->buf = ft_memalloc(BUFF_SIZE + 1);
		(*fdlist)->next = 0;
		return ((*fdlist)->buf);
	}
	else
	{
		if ((*fdlist)->fd == fd)
			return ((*fdlist)->buf);
		else
		{
			if ((*fdlist)->next)
				return (get_buf(&((*fdlist)->next), fd));
			(*fdlist)->next = (t_fdlist *)malloc(sizeof(t_fdlist));
			(*fdlist)->next->fd = fd;
			(*fdlist)->next->buf = ft_memalloc(BUFF_SIZE + 1);
			(*fdlist)->next->next = 0;
			return ((*fdlist)->next->buf);
		}
	}
}

static int	ft_clear_all(char **line, t_fdlist **fdlist, int ret, int fd)
{
	t_fdlist	*lst;
	t_fdlist	*temp;

	if (!ret && **line != 0)
		return (1);
	temp = 0;
	lst = *fdlist;
	while (lst->fd != fd)
	{
		temp = lst;
		lst = lst->next;
	}
	if (!temp)
		*fdlist = lst->next;
	else
		temp->next = lst->next;
	free(lst->buf);
	free(lst);
	ft_strdel(line);
	if (!ret)
		return (0);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static t_fdlist	*fdlst = 0;
	int				exit;
	char			*buf;

	exit = 0;
	if (fd < 0 || line == 0)
		return (-1);
	buf = get_buf(&fdlst, fd);
	*line = ft_strdup("");
	if (buf[0] && line && fd >= 0)
		exit = add_line(line, buf);
	while (!exit && ((ret = read(fd, buf, BUFF_SIZE)) >= 0))
	{
		if (ret == 0)
			return (ft_clear_all(line, &fdlst, ret, fd));
		buf[ret] = '\0';
		exit = add_line(line, buf);
	}
	if (exit == -1 || ret < 0)
		return (ft_clear_all(line, &fdlst, ret, fd));
	return (1);
}
