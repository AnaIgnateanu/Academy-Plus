NAME = libftprintf.a

SRC = check_format.c \
		ft_printf.c \
		format_subspecifiers.c \
		process_int_args.c \
		get_modif.c \
		ft_itoa_base_prec.c \
		ft_utoa_base_prec.c \
		process_char_args.c \
		utils.c \
		adjust.c \
		get_int_args.c \
		process_float.c \
		process_scientific_not.c \

INCLUDE = libft/

LIBFT = ft_strlen.c \
		ft_strchr.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_strjoin.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_tolower.c \
		ft_pow.c \
		ft_itoa.c

OBJ = $(SRC:.c=.o)

LIBFTOBJ = $(LIBFT:.c=.o)

all : $(NAME) 

$(NAME): 
	gcc -Wall -Werror -Wextra -I $(INCLUDE) -c $(SRC) $(addprefix $(INCLUDE),\
		$(LIBFT))
	ar rc $(NAME) $(OBJ) $(LIBFTOBJ)
	ranlib $(NAME)

clean:
		@rm -f $(OBJ) $(LIBFTOBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re