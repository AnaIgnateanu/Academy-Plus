#include "ft_printf.h"

int 		subspecif(char x)
{
	return (is_flag(x) || is_length_modif(x) || DIGIT(x) || x == '.');
}

void		get_flags(t_param *t, const char	*format, int *i)
{
	while(is_flag(format[*i]))
	{
		if (format[*i] == '#')
			t->flag_sharp = 1;
		else if (format[*i] == '0')
			t->flag_zero = 1;
		else if (format[*i] == '-')
			t->flag_minus = 1;
		else if (format[*i] == '+')
			t->flag_plus = 1;
		else if (format[*i] == ' ')
			t->flag_space = 1;
		(*i)++;
	}
}

void		get_width(t_param *t, const char	*format, int *i)
{
	int		w;

	w = ft_atoi(format + (*i));
	t->width = w;
	while (DIGIT(format[*i]))
		(*i)++;
}

void		get_precision(t_param *t, const char	*format, int *i)
{
	int		p;

	(*i)++;
	p = ft_atoi(format + (*i));
	t->precision = p;
	while (DIGIT(format[*i]))
		(*i)++;
}

void		get_length(t_param *t, const char *format, int *i)
{
	while(is_length_modif(format[*i]))
	{
		if (format[*i] == 'h')
		{
			t->length = H;
			if (format[++(*i)] == 'h')
				t->length = HH;
		}
		else if (format[*i] == 'l')
		{
			t->length = L;
			if (format[++(*i)] == 'l')
				t->length = LL;
		}
		else if (format[*i] == 'z')
			t->length = Z;
		else if (format[*i] == 'j')
			t->length = J;
		(*i)++;
	}
}



