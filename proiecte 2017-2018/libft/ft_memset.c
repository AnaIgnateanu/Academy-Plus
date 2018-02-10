#include "libft.h"

/*Fills the first n bytes of the block of memory 
pointed to by str with the value of c.
Returns a pointer to the memory area str.
*/
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}