#include "ft_printf.h"

# include <unistd.h>
# include <string.h>
# include <limits.h>

int main(void)
{
	ft_printf("42%020ji42\n", -2101817232);
	printf("42%020ji42\n", -2101817232);

	ft_printf("%5c\n", 42);
	printf("%5c\n", 42);

	ft_printf("%05i\n", -42);
	printf("%05i\n", -42);

	ft_printf("%037D\n", 596800101516776418);
	printf("%037D\n", 596800101516776418);

	ft_printf("%20s\n", NULL);
	printf("%20s\n", NULL);

	//printf("%b\n", 256);
	

	return (0);
}