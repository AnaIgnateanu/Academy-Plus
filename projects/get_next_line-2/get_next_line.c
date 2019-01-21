/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:28:19 by amanolac          #+#    #+#             */
/*   Updated: 2018/03/02 17:44:15 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/includes/libft.h"


t_buf		*get_node(t_buf **list, int fd)
{
	t_buf	*t;

	t = *list;
	while (t)
	{
		if (t->id == fd)
			return (t);
		t = t->next;
	}
	if (!(t = malloc(sizeof(t_buf))))
		return (NULL);
	t->content = ft_strnew(BUFF_SIZE);
	t->id = fd;
	t->visited = 0;
	t->next = *list;
	*list = t;
	return (t);
}

int			start_over(int fd, char **line, t_buf *curr)
{
	*line = ft_strdup(curr->content);
	curr->content = ft_strnew(BUFF_SIZE);
	return (parse(fd, line, curr));
}

int			delimit(char **line, t_buf *curr)
{
	int		i;
	char	*s;

	i = 0;
	while (curr->content[i])
	{
		if (curr->content[i] == '\n' || curr->content[i] == '\0')
		{
			curr->visited = 1;
			s = ft_strsub(curr->content, 0, i);
			*line = ft_strjoin(*line, s);
			free(s);
			s = ft_strdup(curr->content);
			free(curr->content);
			curr->content = ft_strsub(s, i + 1, ft_strlen(s));
			free(s);
			return (1);
		}
		i++;
	}
	return (0);
}

int			parse(int fd, char **line, t_buf *curr)
{
	int		ret;

	while ((ret = read(fd, curr->content, BUFF_SIZE)) > 0)
	{
		curr->content[ret] = '\0';
		if (ft_strchr(curr->content, '\n'))
		{
			if (delimit(line, curr))
				return (1);
		}
		*line = ft_strjoin(*line, curr->content);
	}
	if (ret == -1)
		return (-1);
	if (*line[0] == 0)
		return (0);
	if (ret < BUFF_SIZE)
		free(curr->content);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int					ret;
	static t_buf		*list;
	t_buf				*curr;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	curr = get_node(&list, fd); 
	*line = ft_strnew(0);
	if (curr->visited)
	{
		if (delimit(line, curr))
			return (1);
		else
			return (start_over(fd, line, curr));
	}
	ret = parse(fd, line, curr);
	return (ret);
}
