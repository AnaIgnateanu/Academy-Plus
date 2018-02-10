#include "libft.h"

/*Applies the function f to each character of the input string and passing its index as first argument.
Each character is passed by address to f to be modified if necessary.
*/

void	ft_striteri(char *str, void(*f)(unsigned int, char *))
{
	unsigned int 	i;

	i = 0;
	if (str != NULL && f != NULL)
	{
		while (*str)
		{
			f(i, str);
			i++;
			str++;
		}

	}
}