#include "ft_printf.h"

char	*get_int(char c, va_list *list, t_param *t)
{
	char		*s;
	char		*temp;
	intmax_t 	n;

	n = get_i(c, list, t->length);
	//printf("%D\n", n);
	modif_width(t, n);
	s = ft_itoa_base_prec(n, 10, modif_precision(t));
	//printf("precision %d\n",t->precision);
	if (ft_strchr(s, '-') == NULL)
	{
		if (t->flag_plus == 1)
			temp = ft_strjoin("+", s);
		else if (t->flag_space == 1)
			temp = ft_strjoin(" ", s);
		else
			temp = ft_strdup(s);
		free(s);
		s = ft_strdup(temp);
		free(temp);
	}
	n = check_width(t);
	//printf("w %d\n", w);
	if (check_justify(t))
		s = pad(&s, " ", n, 0);
	if (t->flag_minus == 1)
		s = pad(&s, " ", n, 1);
	return (s);
}

char	*get_oct(char c, va_list *list, t_param *t)
{
	char		*s;
	char		*temp;
	int 		w;
	uintmax_t 	n;

	modif_precision(t);
	if (t->flag_sharp == 1 && t->precision - 1 > 0)
		t->precision--;
	n = get_u(c, list, t->length);
	s = ft_utoa_base_prec(n, 8, t->precision);
	w = check_width(t);
	if (t->flag_sharp == 1 && (n > 0 || t->precision == 0))
	{
		temp = ft_strjoin("0", s);
		free(s);
		s = ft_strdup(temp);
		free(temp);
	}
	if (check_justify(t))
		s = pad(&s, " ", w, 0);
	if (t->flag_minus == 1)
		s = pad(&s, " ", w, 1);
	return (s);
}

char	*get_hex(char c, va_list *list, t_param *t)
{
	char		*s;
	char		*temp;
	uintmax_t	n;
	int 		w;

	modif_precision(t);
	if ((t->flag_sharp == 1 || PTR_SPECIF(c)) && t->precision - 2 > 0 
		&& t->precision == t->width)
		t->precision -= 2;
	n = get_u(c, list, t->length);
	w = check_width(t);
	s = ft_utoa_base_prec(n, 16, t->precision);
	if ((t->flag_sharp == 1 && n != 0) || PTR_SPECIF(c))
	{
		temp = ft_strjoin("0X", s);
		free(s);
		s = ft_strdup(temp);
		free(temp);
	}
	if (check_justify(t))
		s = pad(&s, " ", w, 0);
	if (t->flag_minus == 1)
		s = pad(&s, " ", w, 1);
	if (HEX_SPECIF(c) || PTR_SPECIF(c))
		s = ft_strmapf(s, (char (*)(char))ft_tolower);
	return (s);
}

char	*get_uint(char c, va_list *list, t_param *t)
{
	char	*s;
	uintmax_t	n;
	int 		w;

	modif_precision(t);
	n = get_u(c, list, t->length);
	s = ft_utoa_base_prec(n, 10, t->precision);
	w = check_width(t);
	if (check_justify(t))
		s = pad(&s, " ", w, 0);
	if (t->flag_minus == 1)
		s = pad(&s, " ", w, 1);
	return (s);
}

int		process_number(char c, va_list *list, t_param *t)
{
	char	*s;
	int 	l;

	if (INT_SPECIF(c) || LONG_SPECIF(c))
		s = get_int(c, list, t);
	else if (OCT_SPECIF(c) || L_OCT_SPECIF(c))
		s = get_oct(c, list, t);
	else if (U_INT_SPECIF(c) || U_LONG_SPECIF(c))
		s = get_uint(c, list, t);
	else if (HEX_SPECIF(c) || C_HEX_SPECIF(c) || PTR_SPECIF(c))
		s = get_hex(c, list, t);
	else if (L_FLOAT_SPECIF(c) || U_FLOAT_SPECIF(c) || SCI_SPECIF(c) || L_SCI_SPECIF(c)
		|| FE_SPECIF(c) || L_FE_SPECIF(c))
		s = get_float(c, list, t);
	else
		return (0);
	l = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (l);
}

