#include "libft.h"

/*Takes as a parameter the address of a string that needs to be freed with free(3),
then sets its pointer to NULL.
*/

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}