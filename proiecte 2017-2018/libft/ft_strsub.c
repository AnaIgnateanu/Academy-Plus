#include "libft.h"

/*Allocates with malloc and returns a 'fresh' substring from the string given as argument.
The substring begins at index start and is of size len. 
If start and len aren't refering to a valid substring the behaviour is undefined.
If the allocation fails, the functions returns NULL.
*/

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = NULL;
	if (str != NULL)
	{
		substr = (char *)malloc(len + 1);
		if (substr == NULL)
			return (NULL);
		while (i < len)
		{
			substr[i] = str[start];
			start++;
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}