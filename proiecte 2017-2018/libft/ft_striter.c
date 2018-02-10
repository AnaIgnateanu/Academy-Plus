#include "libft.h"

/*Applies the function f to each character of the input string. 
Each character is passed by address to f to be modified if necessary.
*/

void	ft_striter( char *str, void (*f)(char *))
{
	if (str != NULL && f != NULL)
	{
		while (*str)
		{
			f(str);
			str++;
		}
	}
}