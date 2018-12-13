/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:21:44 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/13 09:49:30 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		lst_del(t_saved **lst, int fd, int ret)
{
	t_saved		*tmp;
	int			select;

	tmp = NULL;
	select = (fd == -1) ? -1 : fd;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		if (select == -1 || (*lst)->fd == select)
		{
			free((*lst)->saved_buf);
			free(*lst);
		}
		*lst = tmp;
	}
	return (ret);
}

static char		*save_buff(t_saved **lst, int fd, char *saved_buf, char *buf)
{
	t_saved		*elm;
	char		*tmp;

	elm = *lst;
	while (elm)
	{
		if (elm->fd == fd)
		{
			tmp = elm->saved_buf;
			elm->saved_buf = ft_strjoin(saved_buf, buf);
			free(tmp);
			return (elm->saved_buf);
		}
		elm = elm->next;
	}
	elm = *lst;
	if (!(*lst = (t_saved *)malloc(sizeof(**lst))))
		return (NULL);
	if (!((*lst)->saved_buf = ft_strjoin(saved_buf, buf)))
		return (NULL);
	(*lst)->fd = fd;
	(*lst)->next = elm;
	return ((*lst)->saved_buf);
}

static char		*get_saved_buf(t_saved **lst, int fd)
{
	t_saved		*elm;

	if (!lst)
		return ("");
	elm = *lst;
	while (elm)
	{
		if (elm->fd == fd)
			return (elm->saved_buf);
		elm = elm->next;
	}
	return ("");
}

static int		get_line(char *saved_buf, char **line, t_saved **lst, int fd)
{
	if (!(*line = ft_strdup_c(saved_buf, '\n')))
		return (lst_del(lst, fd, -1));
	if (ft_strchr(saved_buf, '\n'))
	{
		if (!save_buff(lst, fd, ft_strchr(saved_buf, '\n') + 1, ""))
			return (lst_del(lst, fd, -1));
	}
	else
	{
		if (!save_buff(lst, fd, "", ""))
			return (lst_del(lst, fd, -1));
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_saved	*lst = NULL;
	char			*saved_buf;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	saved_buf = get_saved_buf(&lst, fd);
	if (ft_strchr(saved_buf, '\n'))
		return (get_line(saved_buf, line, &lst, fd));
	while (!ft_strchr(saved_buf, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = 0;
		if (ret == -1)
			return (lst_del(&lst, fd, -1));
		if (ret == 0 && saved_buf[0])
			return (get_line(saved_buf, line, &lst, fd));
		if (ret == 0 && !saved_buf[0])
			return (lst_del(&lst, fd, 0));
		saved_buf = save_buff(&lst, fd, saved_buf, buf);
	}
	return (get_line(saved_buf, line, &lst, fd));
}
