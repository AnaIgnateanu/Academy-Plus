#include "ft_printf.h"

void	get_wchar(va_list *list, int *w)
{
	char 	*temp;

	wint_t wchar = va_arg(*list, wchar_t);
	temp = wchar_to_char(wchar, 0);
	*w += (*temp == '\0') ? write(1, "\0", 1) : wchar_size(wchar);
	ft_putstr(temp);
	free(temp);
}

int		get_char(char c, va_list *list, t_param *t)
{
	int		w;
	char 	*s;

	w = check_width_char(t);
	s = ft_strnew(1);
	if (t->flag_zero == 1 && t->flag_minus == -1)
		s = pad(&s, "0", w, 0);
	else
		s = pad(&s, " ", w, 0);
	if (t->flag_minus != 1)
		ft_putstr(s);
	if (CHAR_SPECIF(c) && t->length != L)
		ft_putchar(va_arg(*list, int));
	else if (!CHAR_SPECIF(c) && !W_CHAR_SPECIF(c))
		ft_putchar(c);
	else
		get_wchar(list, &w);
	if (!W_CHAR_SPECIF(c) && !(CHAR_SPECIF(c) && t->length == L))
		w++;
	if (t->flag_minus == 1)
		ft_putstr(s);
	free(s);
	return (w);
}

char 	*wstr_to_str(wchar_t *str)
{
	int		i;
	char	*s;
	char	*w;

	i = 0;
	if (str == NULL)
		return (NULL);
	s = ft_strnew(1);
	while (str[i] != L'\0')
	{
		w = wchar_to_char(str[i++], 0);
		s = ft_strjoinf(s, w);
	}
	return (s);
}

int		get_str(char c, va_list *list, t_param *t)
{
	char 	*s;
	int 	l;

	if (STR_SPECIF(c) && t->length != L)
		s = ft_strdup(va_arg(*list, char *));
	else
		s = wstr_to_str(va_arg(*list, wchar_t *));
	if (s == NULL)
		s = ft_strdup("(null)");
	s = modif_str(c, t, s);
	l = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (l);
}

int		get_n(va_list *list, t_param *t)
{
	*va_arg(*list, int *) = t->l;
	t->n = 1;
	return (t->l);
}

int		process_char(char c, va_list *list, t_param *t)
{
	if (STR_SPECIF(c) || W_STR_SPECIF(c))
		return (get_str(c, list, t));
	else if (N_SPECIF(c))
		return (get_n(list, t));
	else
		return (get_char(c, list, t));
}