#include "libft.h"

/*Allocates with malloc and returns a 'fresh' string ending with '\0'.
Each character of the string is initialized at '\0'. If the allocation fails the function returns NULL.
*/

char 	*ft_strnew(size_t size)
{
	char 	*str;
	size_t	i;

	i = 0;
	str = (char *) malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}