#include "libft.h"

/*Appends a copy of the string pointed to by s2 to the end of the string 
pointed to by s1.
Returns a pointer to s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s1);
	while (s2[i])
	{
		s1[l + i] = s2[i];
		i++;
	}
	s1[l + i] = '\0';
	return (s1);
}