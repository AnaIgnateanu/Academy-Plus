/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:32:49 by amanolac          #+#    #+#             */
/*   Updated: 2018/03/02 16:32:56 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_buf
{
	char			*content;
	int				id;
	int 			visited;
	struct s_buf	*next;
}				t_buf;

# define BUFF_SIZE 100

int			get_next_line(const int fd, char **line);
int			parse(int fd, char **line, t_buf *curr);


#endif
