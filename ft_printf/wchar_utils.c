#include "ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

void	ft_putwstrp(char *str, int precision)
{
	if ((precision != -1) && ((size_t)precision < ft_strlen(str)))
	{
		while (precision--)
		{
			ft_putchar(*str);
			str++;
		}
	}
	else
		ft_putstr(str);
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

int			wstring_size(wchar_t *arg)
{
	int		i;
	int		w_size;
	int		w_char;

	i = 0;
	w_size = 0;
	w_char = 0;
	while (arg[i])
	{
		w_char = wchar_size(arg[i++]);
		if (w_char == 0)
			return (-1);
		w_size = w_size + w_char;
	}
	return (w_size);
}



