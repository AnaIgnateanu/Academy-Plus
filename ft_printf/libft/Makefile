# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanolac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 17:58:00 by amanolac          #+#    #+#              #
#    Updated: 2018/03/02 16:35:58 by amanolac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c \
		ft_strchr.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_memmove.c \
		ft_lstdelone.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_strcpy.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strmap.c \
		ft_tolower.c \
		ft_pow.c
		

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = ./includes/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
