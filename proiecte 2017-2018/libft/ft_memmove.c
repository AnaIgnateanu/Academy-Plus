#include "libft.h"

/*Copies the first n bytes pointed to by src to the buffer pointed to by dest.
Source and destination may overlap.
Returns a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (dest == src)
		return (dest);
	if (src>dest)
	{
		while (n--)
			*d++= *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}