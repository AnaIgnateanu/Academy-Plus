NAME = fillit

SRC = main.c\
		read.c\
		solve.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

HEADER = fillit.h

CC = gcc 

FLAGS = -Wall -Wextra -Werror -g
# name for executable
EXE = fillit

all : $(NAME) 

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c $(HEADER) $(LIBFT)
		$(CC) $(FLAGS) -c $< -o $@ 

$(LIBFT):
		@make -C libft

clean:
		@make clean -C libft
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re