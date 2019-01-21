#include "libft.h"

/*Computes the length of the string str up to, but not including 
the terminating null character.
*/
size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}