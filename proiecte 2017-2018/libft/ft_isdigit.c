#include "libft.h"

/*Checks for a digit (0 through 9). Returns nonzero if it is, zero if it isn't.
*/

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}