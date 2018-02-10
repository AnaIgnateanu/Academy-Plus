#include "libft.h"

/*Checks for any printable character including space.
*/

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}