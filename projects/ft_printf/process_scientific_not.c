#include "ft_printf.h"

static char			*ft_exp(long double *n, char c)
{
	int		i;
	char	*s;
	char	*arr;

	i = 0;
	while ((long)(*n))
	{
		*n /= 10.0;
		i++;
	}
	while (!((long)(*n)) && *n != 0.0)
	{
		*n *= 10.0;
		i--;
	}
	i = (i < 0) ? -i : i;
	s = ft_itoa(i);
	arr = (char*)ft_memalloc(3 + ((i > 9 || i < -9) ? ft_strlen(s) : 2));
	*arr = (c == 'E' || c == 'G') ? 'E' : 'e';
	arr[1] = i < 0 ? '-' : '+';
	arr[2] = '0';
	(i > 9 || i < -9) ? ft_strcpy(arr + 2, s) : ft_strcpy(arr + 3, s);
	free(s);
	return (arr);
}

int				length_n(long double f)
{
	int 	count;
	long	l;

	count = 0;
	l = (long) f;
	l = l < 0 ? -l : l;
	while (l / 10 > 0)
	{
		l = l / 10;
		count++;
	}
	return (count);
}

int				trim_str(char *s)
{
	int		i;
	int		digit;

	i = 0;
	digit = 0;
	while (s[i] && digit < 5)
	{
		if (DIGIT(s[i]))
			digit++;
		if (digit == 5)
		{
			i = digit + (digit - i);
			if (ft_strchr(s, '.'))
				i++;
			if (DIGIT(s[i + 1]) && s[i + 1] > '5')
				s[i]++;
			else if (s[i + 1] == '.')
			{
				if (DIGIT(s[i + 2]) && s[i + 2] > '1')
					s[i]++;
			}
		}
		i++;
	}
	i = (s[0] == '-') ? 7 : 6;
	return (i);
}

char				*ft_eftoa(long double n, t_param *t, char c)
{
	char	*s;
	char	*exp;
	char	arr[16] = "0123456789abcdef";
	int 	i;

	if ((FE_SPECIF(c) || L_FE_SPECIF(c)) && length_n(n) < 6)
	{	
		s = ft_ftoa(n, 10.0, t, arr);
		i = trim_str(s);	
		if (get_pos(s, '.') < i)
			i++;
		s[i] = '\0';
		return (s);
	}
	exp = ft_exp(&n, c);
	s = ft_ftoa(n, 10.0, t, arr);
	s = ft_strjoinf(s, exp);
	return (s);
}

char	*get_e(char c, t_param *t, long double f)
{
	char		*s;
	char		*arr;

	arr = "0123456789abcdef";
	if (f != f)
		s = (c == 'e') ? ft_strdup("nan") : ft_strdup("NAN");
	else if (c == 'E' && f == 1.0 / 0.0)
		s = ft_strdup("INF");
	else if (c == 'e' && f == 1.0 / 0.0)
		s = ft_strdup("inf");
	else
		s = ft_eftoa(f, t, c);
	return (s);
}




