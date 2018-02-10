#include "libft.h"

/*Finds the last occurrence of c in str. The ending null character is considered part of the string.
Returns a pointer to the last occurrence of c in str.
If the given character is not found a NULL pointer is returned.
*/

char 	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = (int) ft_strlen(str);
	while (len >=0)
	{
		if (str[len] == (unsigned char)c)
		{
			return ((char *)str + len);
		}
		len--;
	}
	return (NULL);
}

