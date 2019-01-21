#include "ft_printf.h"

int 		modif_precision(t_param *t)
{
	if (t->flag_zero && t->precision == -1)
		t->precision = t->width;
	return (t->precision);
}

void 		modif_width(t_param *t, int n)
{
	if (t->precision == -1 && t->flag_zero &&
		(n < 0 || t->flag_space == 1 || t->flag_plus == 1))
		t->width--;
}

int 		check_width(t_param *t)
{
	if (t->width > 0)
		return (t->width);
	else
		return (0);
}

int 	check_pad_left(t_param *t)
{
	if ((t->flag_zero == 1 && t->width != t->precision) ||
		(t->flag_zero == -1 && t->flag_minus == -1))
		return (1);
	return (0);
}

char		*pad(char **a, char *b, size_t i, int x)
{
	char	*s;
	char	*temp;
	size_t 	l;

	l = ft_strlen(*a);
	if (l >= i || l <= 0)
		return (*a);
	s = ft_strdup(*a);
	ft_strdel(a);
	while (l < i)
	{
		if (x == 1)
			temp = ft_strjoin(s, b);
		else if (x == 0)
			temp = ft_strjoin(b, s);
		free(s);
		s = ft_strdup(temp);
		free(temp);
		l += ft_strlen(b);
	}
	return (s);
}


intmax_t	get_i(char c, va_list *list, int length_modif)
{
	if (length_modif == L || LONG_SPECIF(c))
		return (va_arg(*list, long));
	if (length_modif == HH)
		return ((char)va_arg(*list, int));
	if (length_modif == H)
		return ((short)va_arg(*list, int));
	if (length_modif == LL)
		return (va_arg(*list, long long));
	if (length_modif == J)
		return (va_arg(*list, intmax_t));
	if (length_modif == Z)
		return (va_arg(*list, ssize_t));
	return (va_arg(*list, int));
}

uintmax_t	get_u(char c, va_list *list, int length_modif)
{
	if (length_modif == L || U_LONG_SPECIF(c) || L_OCT_SPECIF(c))
		return (va_arg(*list, unsigned long));
	if (length_modif == HH)
		return ((unsigned char)va_arg(*list, unsigned int));
	if (length_modif == H)
		return ((unsigned short)va_arg(*list, unsigned int));
	if (length_modif == LL)
		return (va_arg(*list, unsigned long long));
	if (length_modif == J)
		return (va_arg(*list, uintmax_t));
	if (length_modif == Z)
		return (va_arg(*list, size_t));
	if (PTR_SPECIF(c))
		return ((unsigned long)va_arg(*list, void *));
	return (va_arg(*list, unsigned int));
}