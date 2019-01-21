#include "libft.h"

/*Compares at most the first n characters of string s1 to string s2. 
It returns an integer less than, equal to, or greater than zero
if s1 is found, respectively, to be less than, to match, or be greater than s2.
*/

int 	ft_strncmp(const char*s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && i < n - 1)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}