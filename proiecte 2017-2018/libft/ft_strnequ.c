#include "libft.h"


/*Lexicographical comparison between s1 and s2 up to n characters or until '\0\ is reached.
If the strings are identical the function returns 1, zero otherwise.
*/

int 	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s2 && --n)
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