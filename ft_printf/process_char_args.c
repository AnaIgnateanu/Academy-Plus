#include "ft_printf.h"

int		wchar_to_char(wint_t wchar, char *str, int i)
{
	int		size;

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
	return (i);
}

int		get_char(char c, va_list *list, t_param *t)
{
	int		w;
	char 	*s;
	char 	*temp;
	int 	i;

	w = check_width(t);
	s = ft_strnew(1);
	temp = NULL;
	if (t->flag_zero == 1)
		pad(&s, "0", w, 0);
	else
		pad(&s, " ", w, 0);
	if (t->flag_minus != 1)
		ft_putstr(s);
	if (CHAR_SPECIF(c) && t->length != L)
		ft_putchar(va_arg(*list, int));
	else if (!CHAR_SPECIF(c) && !W_CHAR_SPECIF(c))
		ft_putchar(c);
	else
	{
		i = wchar_to_char(va_arg(*list, wchar_t), temp, 0);
		w += (*temp == '\0') ? write(1, "\0", 1) : i;
		ft_putstr(temp);
	}
	if (t->flag_minus == 1)
		ft_putstr(s);
	ft_strdel(&s);
	return (W_CHAR_SPECIF(c) || (CHAR_SPECIF(c) && t->length == L) ? w : ++w);

}

char 	*wstr_to_str(wchar_t *ws)
{
	char 	*s;
	int		i;

	i = 0;
	if (ws == NULL)
		return (NULL);
	s = ft_strnew(1);
	while (ws[i] != L'\0')
	{
		i = wchar_to_char(ws[i], s, i);
	}
	return (s);
}

int		get_str(char c, va_list *list, t_param *t)
{
	char 	*s;
	int		w;

	w = check_width(t);
	if (STR_SPECIF(c) && t->length != L)
		s = ft_strdup(va_arg(*list, char *));
	else
		s = wstr_to_str(va_arg(*list, wchar_t *));
	if (s == NULL && t->flag_zero == -1 && t->flag_minus == -1)
	{
		ft_putstr("(null");
		return (ft_strlen("(null"));
	}
	else if (s == NULL)
		s = ft_strnew(1);
	if (t->precision > 0 && (W_STR_SPECIF(c) || t->length == L) && t->precision % 4 == 0)
		t->precision--;
	if (t->precision != -1)
		s = ft_strsub(s, 0, t->precision);
	if (t->flag_zero == 1)
		s = pad(&s, "0", w, 0);
	if (t->flag_minus == 1)
		s = pad(&s, " ", w, 1);
	else
		s = pad(&s, " ", w, 0);
	ft_putstr(s);
	w = ft_strlen(s);
	ft_strdel(&s);
	return (w);
}

int		process_char(char c, va_list *list, t_param *t)
{
	if (STR_SPECIF(c) || W_STR_SPECIF(c))
		return (get_str(c, list, t));
	if (!STR_SPECIF(c) && !W_STR_SPECIF(c))
		return (get_char(c, list, t));
	return (0);
}