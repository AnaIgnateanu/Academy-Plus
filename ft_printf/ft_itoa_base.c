#include "ft_printf.h"

size_t		length(long n, int base)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*get_arr(int lowercase)
{
	char	*arr;

	if (lowercase)
		arr = ft_strdup("0123456789abcdef");
	else
		arr = ft_strdup("0123456789ABCDEF");
	return (arr);
}

char	*ft_itoa_base_u(unsigned long n, int base, int lowercase)
{
	char	*arr;
	int		l;
	char	*str;
	int		i;

	if (!base)
		return (NULL);
	arr = get_arr(lowercase);
	l = length(n, base);
	str = (char*)malloc(sizeof(char) * (l + 1));
	i = l - 1;
	str[l] = '\0';
	if (!n)
		str[i--] = arr[n % base];
	while (n)
	{
		str[i--] = arr[n % base];
		n /= base;
	}
	free(arr);
	return (str);
}

static int		base_length(intmax_t value, int base)
{
	int len;

	len = 0;
	if (value == 0)
		return (len);
	if (value < 0)
		value *= -1;
	while (value >= base)
	{
		value /= base;
		len++;
	}
	return (len);
}

static char		*to_str(intmax_t n, int len, int base)
{
	char		*arr;
	char		*s;
	int			l;
	int 		i;

	i = 0;
	arr = get_arr(1);
	l = base_length(n, base);
	if (n < 0)
		n *= -1;
	if (n < 0 && base == 10)
	{
		s = ft_strnew(len + 2);
		s[i++] = '-';
	}
	else
		s = ft_strnew(len + 1);
	if (len > l)
		while (--len > l)
			s[i++] = '0';
	while (len >= 0 && n != 0)
		s[i++] = arr[(n / (intmax_t)ft_pow(base, len--)) % base];
	s[i] = (n == 0) ? '0' : s[i];
	return (s);
}

char			*ft_itoa_base(intmax_t value, int base, int precision)
{
	int	len;

	if (base < 2 || base > 16)
		return (ft_strdup("Invalid base"));
	if (value < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (precision == 0 && value == 0)
		return (ft_strnew(1));
	len = base_length(value, base);
	if (len < precision)
		len = precision;
	return (to_str(value, len, base));
}