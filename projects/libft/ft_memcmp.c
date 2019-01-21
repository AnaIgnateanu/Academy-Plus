#include "libft.h"

/*Compares the first n bytes of the object pointed to by s1 to the first n bytes of
the object pointed to by s2;
Returns a negative, zero, or positive integer depending on whether the object 
pointed to by s1 is less than, equal to, or greater than the object pointed to by s2.
*/

int 	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (n--)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}