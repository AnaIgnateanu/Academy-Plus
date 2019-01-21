NAME = ft_printf

SRC = check_format.c \
		ft_printf.c \
		format_subspecifiers.c \
		process_int_args.c \
		get_modif.c \
		ft_itoa_base.c \
		ft_utoa_base.c \
		process_char_args.c \
		wchar_utils.c \

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

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