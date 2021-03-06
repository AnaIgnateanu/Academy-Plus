#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>
# include "./libft/includes/libft.h"

typedef struct	s_param
{
	int 		flag_sharp;
	int 		flag_zero;
	int 		flag_minus;
	int 		flag_plus;
	int 		flag_space;
	int 		padding;
	int			sign;
	int			width;
	int			precision;
	int 		length;
}				t_param;

# define STR_SPECIF(x) (x == 's')
# define W_STR_SPECIF(x) (x == 'S')
# define PTR_SPECIF(x) (x == 'p')
# define INT_SPECIF(x) (x == 'd' || x == 'i')
# define LONG_SPECIF(x) (x == 'D')
# define OCT_SPECIF(x) (x == 'o')
# define L_OCT_SPECIF(x) (x == 'O')
# define U_INT_SPECIF(x) (x == 'u')
# define U_LONG_SPECIF(x) (x == 'U')
# define HEX_SPECIF(x) (x == 'x')
# define C_HEX_SPECIF(x) (x == 'X')
# define CHAR_SPECIF(x) (x == 'c')
# define W_CHAR_SPECIF(x) (x == 'C')
# define DIGIT(x) (x >= '0' && x <= '9')
# define H 0
# define HH 1
# define L 2
# define LL 3
# define J 4
# define Z 5




int			ft_printf(const char *format, ...);
void		get_flags(t_param *t, const char	*format, int *i);
void		get_width(t_param *t, const char	*format, int *i);
void		get_precision(t_param *t, const char	*format, int *i);
void		get_length(t_param *t, const char	*format, int *i);
//---------
int 		is_flag(char c);
int 		is_length_modif(char c);
int 		is_num_specif(char c);
int 		is_long_specif(char c);
int 		is_char_specif(char c);
int 		subspecif(char c);
//---------
int			process_number(char c, va_list *list, t_param *t);
int			process_char(char c, va_list *list, t_param *t);

//----------
intmax_t	get_i(char c, va_list *list, int length_modif);
uintmax_t	get_u(char c, va_list *list, int length_modif);

int 		check_precision(t_param *t);
void 		modif_width(t_param *t, int n);
int 		modif_precision(t_param *t);
int 		check_width(t_param *t);
char		*pad(char **a, char *b, size_t i, int x);
int 		check_pad_left(t_param *t);
char			*ft_itoa_base(intmax_t value, int base, int precision);
char			*ft_utoa_base(uintmax_t value, int base, int precision);
intmax_t		ft_pow(int base, int exp);

int			wchar_size(wint_t c);
int			wstring_size(wchar_t *arg);








#endif