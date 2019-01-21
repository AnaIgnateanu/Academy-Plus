#include "ft_printf.h"

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
			t->length = H > t->length ? H : t->length;
		else if (format[*i] == 'l')
			t->length = L > t->length ? L : t->length;
		else if (format[*i] == 'z')
			t->length = Z > t->length ? Z : t->length;
		else if (format[*i] == 'j')
			t->length = J > t->length ? J : t->length;
		else if (format[*i] == 'L')
			t->length = LD > t->length ? LD : t->length;
		if (*i > 0 && format[(*i)] == 'h' && format[(*i + 1)] == 'h')
		{
			t->length = HH > t->length ? HH : t->length;
			(*i)++;
		}
		else if (*i > 0 && format[(*i)] == 'l' && format[(*i + 1)] == 'l')
		{
			t->length = LL > t->length ? LL : t->length;
			(*i)++;
		}	
		(*i)++;
	}
}



