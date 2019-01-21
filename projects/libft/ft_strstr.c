#include "libft.h"

/*Finds the first occurrence of the substring s2 in the string s1.
The terminating null characters are not compared.
Returns a pointer to the beginning of the substring, or NULL if the substring is not found.
If s2 is an empty string, s1 is returned.
*/


char 	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i + j] == s2[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
	}
	return (NULL);
}