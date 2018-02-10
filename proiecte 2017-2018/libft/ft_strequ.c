#include "libft.h"


/*Lexicographical comparison between s1 and s2. If the strings are identical the function returns 1, 
zero otherwise.
*/

int 	ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s2)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		if (*s1 == *s2)
			return (1);
	}
	return (0);
}