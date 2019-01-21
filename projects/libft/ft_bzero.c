#include "libft.h"

/*Erases the data in the n bytes of the memory starting 
at the location pointed to by str, by writting zeroes to that area.
*/
void	ft_bzero(void *str, size_t n)
{
	ft_memset((void *)str, 0, (size_t) n);
}