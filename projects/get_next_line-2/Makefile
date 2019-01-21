NAME = get_next_line

SRC = get_next_line.c \
		main.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

HEADER = get_next_line.h

CC = gcc 

FLAGS = -Wall -Wextra -Werror

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