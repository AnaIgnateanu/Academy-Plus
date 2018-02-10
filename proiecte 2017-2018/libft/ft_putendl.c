#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s != NULL)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
		ft_putchar('\n');
	}
}