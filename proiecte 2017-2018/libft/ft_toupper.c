#include "libft.h"

/*Converts the lowercase letter c to the corresponding uppercase letter.
*/


int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}