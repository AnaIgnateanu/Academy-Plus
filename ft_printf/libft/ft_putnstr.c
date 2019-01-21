#include "./includes/libft.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	while (str[++i] && (i < n))
		ft_putchar(str[i]);
}