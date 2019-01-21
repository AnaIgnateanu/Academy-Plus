#include "libft.h"

/*Compares the two string s1 and s2. It returns an integer less than, equal to, or greater than zero
if s1 is found, respectively, to be less than, to match, or be greater than s2.
*/

int 	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}