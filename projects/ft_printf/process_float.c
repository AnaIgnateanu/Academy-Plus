#include "ft_printf.h"


static void	round(char *n, int base, char *arr)
{
	char	*end;

	end = n;
	if (*n >= arr[base / 2])
	{
		n--;
		while (*n == arr[base - 1] || *n == '.')
		{
			if (*n != '.')
				*n = '0';
			n--;
		}
		*n = arr[(*n - '0') + 1];
	}
	*end = '\0';
}

static void	conv(char *n, long double f, t_param *t, float base)
{
	char 	*arr;

	arr = "0123456789abcdef";
	if (t->precision == -1)
	{
		*n = arr[(int)(f * base)];
		round(n, (int)base, arr);
	}
	else
	{
		*n++ = '.';
		t->precision++;
		while (t->precision--)
		{
			f *= base;
			*n++ = arr[(int)f];
			f -= (int)f;
		}
		*n = '\0';
		round(n - 1, (int)base, arr);
	}
}

long double	get_f(t_param *t, va_list *list)
{
	long double	f;

	f = t->length == LD ? va_arg(*list, long double) : va_arg(*list, double);
	return (f);
}

char		*ft_ftoa(long double f, float base, t_param *t, char *arr)
{
	char		*n;
	long double	power;
	int			len;
	int			digit;
	int			i;
	int			sign;

	power = 1.0;
	len = 2;
	sign = (f < 0.0) ? -1 : 1;
	f *= (f < 0.0) ? -1 : 1;
	while (power < f / base && len++)
		power *= base;
	n = (char *)malloc(len + (t->precision > 0) + t->precision + 1);
	i = 0;
	if (sign < 0)
		n[i++] = '-';
	while (power > 0.0)
	{
		digit = (int)(f / power);
		n[i++] = arr[digit];
		f -= digit * power;
		power = (power != 1.0) ? power / base : 0.0;
	}
	conv(&n[i], f, t, base);
	return (n);
}

char	*get_float(char c, va_list *list, t_param *t)
{
	char		*s;
	char		*arr;
	long double	f;

	arr = "0123456789abcdef";
	t->precision = (t->precision != -1) ? t->precision : 6;
	f = get_f(t, list);
	if (FE_SPECIF(c) || L_FE_SPECIF(c))
		t->precision--;
	if (SCI_SPECIF(c) || L_SCI_SPECIF(c) || FE_SPECIF(c) || L_FE_SPECIF(c))
		return (get_e(c, t, f));
	if (f != f)
		s = (c == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
	else if (c == 'F' && f == 1.0 / 0.0)
		s = ft_strdup("INF");
	else if (c == 'f' && f == 1.0 / 0.0)
		s = ft_strdup("inf");
	else
		s = ft_ftoa(f, 10.0, t, arr);
	return (s);
}