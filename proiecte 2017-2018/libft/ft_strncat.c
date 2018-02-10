#include "libft.h"

/*Appends a copy of the string pointed to by s2 to the end of the string pointed to
by s1. Will stop copying when a null character is encountered or after n characters
have been copied.
Returns a pointer to s1.
*/

char 	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[l + i] = s2[i];
		i++;
	}
	s1[i + l] = '\0';
	return (s1);
}