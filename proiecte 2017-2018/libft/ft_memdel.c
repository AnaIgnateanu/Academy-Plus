#include "libft.h"

/*Takes as a parameter the address of a memory area that needs to be freed with free(3),
then puts he pointer to NULL.
Doesn't return anything.
*/

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}