#include "libft.h"

/*Finds the first occurrence of a character in a string.
The character c can be the nul character (\0); the ending null character of str is included in the search.
Returns a pointer to the first occurrence of c that is converted to a character in string.
Returns NULL if the specified character is not found.
*/

char 	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
