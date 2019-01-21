#include "ft_printf.h"


char 		*modif_str(char c, t_param *t, char *s)
{
	int		w;

	w = check_width(t);
	if (t->precision > 0 && (W_STR_SPECIF(c) || t->length == L) && t->precision % 4 == 0)
		t->precision--;
	if (t->precision != -1)
		s = ft_strsub(s, 0, t->precision);
	if (t->flag_zero == 1 && t->flag_minus == -1)
		s = pad(&s, "0", w, 0);
	else if (t->flag_minus == 1)
		s = pad(&s, " ", w, 1);
	else
		s = pad(&s, " ", w, 0);
	return (s);
}

char		*pad(char **a, char *b, size_t i, int x)
{
	char	*s;
	char	*temp;
	size_t 	l;

	l = ft_strlen(*a);
	if (l >= i || i <= 0)
		return (*a);
	s = ft_strdup(*a);
	free(*a);
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

int			wchar_size(wint_t c)
{
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x10ffff)
		return (4);
	return (0);
}

char		*wchar_to_char(wint_t wchar, int i)
{
	int		size;
	char 	*str;

	str = ft_strnew(4);
	size = wchar_size(wchar);
	if (size == 1)
		str[i++] = wchar;
	else if (size == 2)
	{
		str[i++] = (wchar >> 6) + 0xC0;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		str[i++] = (wchar >> 12) + 0xE0;
		str[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		str[i++] = (wchar >> 18) + 0xF0;
		str[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		str[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	return (str);
}