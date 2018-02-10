#include "libft.h"

/* Copies bytes from memory area src into dest, stopping after the first occurence of c 
has been copied, or after n bytes have been copied, whichever comes first.*/
/*If c was not found in the first n bytes of s2, returns a NULL pointer.
If succesful, returns a pointer to the byte after the copy of c in s1.
*/
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)dest)[i] == (unsigned char)c)
		{
			return (dest+ i + 1);
		}
		i++;
	}
	return (NULL);
}