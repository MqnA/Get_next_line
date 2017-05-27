/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:37:30 by mavagner          #+#    #+#             */
/*   Updated: 2016/12/14 16:25:26 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			check_fd(t_content **list, int fd)
{
	t_content		*stock;
	t_content		*tmp;

	stock = *list;
	tmp = *list;
	if ((*list)->my_fd == fd)
		(*list) = (*list)->next;
	else
	{
		while (stock->next->my_fd != fd && stock->next)
			stock = stock->next;
		tmp = stock->next;
		stock->next = stock->next->next;
	}
	free(tmp->content);
	free(tmp);
	tmp = NULL;
	return (0);
}

static t_content	*check_and_creat_node(int check, t_content **stock, int fd)
{
	t_content		*node;

	if (check == 1)
	{
		if (!(node = (t_content*)malloc(sizeof(t_content))))
			return (NULL);
		node->content = NULL;
		node->my_fd = fd;
		node->next = NULL;
	}
	else
	{
		node = *stock;
		while (node->my_fd != fd)
		{
			node = node->next;
			if (node == NULL)
				return (NULL);
		}
	}
	return (node);
}

static char			*sub_line(t_content **cpy, int i)
{
	char			*line;

	line = ft_strsub(CPY, 0, i);
	CPY = ft_strsub_free(CPY, i + 1, ft_strlen(CPY) - ft_strlen(line));
	IF_LINE = 1;
	return (line);
}

static char			*join_line(t_content **cpy)
{
	int				i;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	ret = 1;
	if (!CPY)
		if (!(CPY = (char*)ft_memalloc(sizeof(char) * 1)))
			return (NULL);
	while (ret != 0)
	{
		if ((ret = read(MY_FD, buff, BUFF_SIZE)) < 0)
			return (NULL);
		buff[ret] = '\0';
		if (!(CPY = ft_strjoin_free(CPY, buff)))
			return (NULL);
		i = -1;
		while ((CPY)[++i])
			if ((CPY)[i] == '\n')
				return (sub_line(cpy, i));
	}
	if (i > 0)
		return (sub_line(cpy, i));
	else
		IF_LINE = 0;
	return (CPY);
}

int					get_next_line(const int fd, char **line)
{
	t_content			*data;
	static	t_content	*stock = NULL;

	if (!line)
		return (-1);
	if (!stock)
		stock = check_and_creat_node(1, NULL, fd);
	if ((data = check_and_creat_node(0, &stock, fd)) == NULL)
	{
		data = stock;
		while (data->next)
			data = data->next;
		data->next = check_and_creat_node(1, NULL, fd);
		data = data->next;
	}
	if (!(*line = join_line(&data)))
		return (-1);
	if (data->if_line == 0)
		return (check_fd(&stock, fd));
	return (data->if_line);
}
