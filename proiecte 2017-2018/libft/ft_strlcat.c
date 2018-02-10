#include "libft.h"

/*Appends the null-terminated src to the end of dest and nul-terminates the resulting string.
Appends at most size - strlen(dest) -1.
Returns the total length of the resulting string.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	const char *s;
	size_t	l;
	size_t	n;

	d = dst;
	s = src;
	n = size;
	while (*d != '\0' && n -- != 0)
		d++;
	l = d - dst;
	n = size - l;
	if (n == 0)
		return (l + ft_strlen(src));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (l + (s - src));


	// while (src[i] && i < (size - 1))
	// {
	// 	dst[l + i] = src[i];
	// 	i++;
	// }
	// if (i)
	// dst[l + i] = '\0';
	// return (l + i);
}