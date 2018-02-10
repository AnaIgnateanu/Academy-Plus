#include "libft.h"

/*Checks for an alphabetic character. Returns nonzero if it is, zero if it isn't.
*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}