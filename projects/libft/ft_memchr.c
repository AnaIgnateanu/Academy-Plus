#include "libft.h"

/*Searches within the first n bytes of the object pointed to by s for the character c.
Returns a pointer to the first occurence of the character c.
If c isn't found a null pointer is returned.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}