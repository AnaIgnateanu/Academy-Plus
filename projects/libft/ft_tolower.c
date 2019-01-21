#include "libft.h"

/*Converts the uppercase letter C to the corresponding lowercase letter.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}