#include "ft_printf.h"

static int		base_length(intmax_t n, int base)
{
	int l;

	l = 0;
	if (n == 0)
		return (l);
	if (n < 0)
		n *= -1;
	while (n >= base)
	{
		n /= base;
		l++;
	}
	return (l);
}

static char		*convert(intmax_t n, int len, int base)
{
	static char	*digits = "0123456789ABCDEF";
	char		*out;
	int			l;
	int 		i;

	i = 0;
	l = base_length(n, base);
	//printf("l %d\n", l);
	if (n < 0)
	{
		n *= -1;
		if (base == 10)
		{
			out = ft_strnew(len + 2);
			out[i++] = '-';
		}
	}
	else if (n >= 0 || base != 10)
		out = ft_strnew(len + 1);
	if (len > l)
		while (--len > l)
			out[i++] = '0';
	while (len >= 0 && n != 0)
		out[i++] = digits[(n / (intmax_t)ft_pow(base, len--)) % base];
	out[i] = (n == 0) ? '0' : out[i];
	
	//printf("out\n%s\n", out);
	return (out);
}

char			*ft_itoa_base_prec(intmax_t n, int base, int precision)
{
	int	l;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (precision == 0 && n == 0)
		return (ft_strnew(1));
	l = base_length(n, base) < precision ? precision : base_length(n, base);
	return (convert(n, l, base));
}
