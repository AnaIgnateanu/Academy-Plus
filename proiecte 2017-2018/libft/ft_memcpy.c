#include "libft.h"

/*Copies n bytes from memory area src to memory area dest.
The memory area must not overlap.
Returns a pointer to dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	while (i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	return ((void *)(dest));
}