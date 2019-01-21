#include "ft_printf.h"

t_param		*init(int i)
{
	t_param	*t;

	t = (t_param*)malloc(sizeof(t_param) * 1);
	t->flag_sharp = i;
	t->flag_zero = i;
	t->flag_minus = i;
	t->flag_plus = i;
	t->flag_space = i;
	t->padding = i;
	t->sign = i;
	t->width = i;
	t->precision = i;
	t->length = i;
	return (t);
}

/* A format specifier follows this prototype:  
	%[flags][width][.precision][length]specifier
*/

int		param(const char *format, va_list *list, int *i)
{
	int				r;
	static t_param			*t;

	r = 0;
	t = init(-1);
	while (format[*i] && subspecif(format[*i]))
	{
		if (is_flag(format[*i]))
			get_flags(t, format, i);
		if (DIGIT(format[*i]))
			get_width(t, format, i);
		if (format[*i] == '.')
			get_precision(t, format, i);
		if (is_length_modif(format[*i]))
			get_length(t, format, i);
	}
	if (is_num_specif(format[*i]) || is_long_specif(format[*i]))
	{
		r = process_number(format[(*i)], list, t);
		(*i)++;
	}
	else if (format[*i])
		r = process_char(format[(*i)++], list, t);
	free(t);
	return (r);
}

int		ft_vprintf(const char *format, va_list *list)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
				n += param(format, list, &i);
		}
		else if (format[i] != '\0')
		{
			ft_putchar(format[i++]);
			n++;
		}
	}
	return (n);
}


int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			n;

	if (!format || !*format)
		return (0);
	va_start(list, format);
	n = ft_vprintf(format, &list);
	va_end(list);
	return (n);
}

int main(void)
{
	ft_printf("'%10s' \n", "Hello");
	ft_printf("'%10d' \n", -23);
	ft_printf("%zd%zd \n", 0, 42);
	ft_printf("%+d \n", 42);
	return (0);
}