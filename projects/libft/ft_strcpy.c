#include "libft.h"

/*Copies the string pointed to by src into the object pointed to by dest.
It returns a pointer to the destination.
*/

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}