#include "libft.h"

void bzero(void *str, size_t n)
{
	ft_memset((void *)str, 0, (size_t) n);
}