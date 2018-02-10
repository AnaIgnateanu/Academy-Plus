#include "libft.h"

/*Locates the first occurrence of the null-terminated string s2 in the null-terminated string s1, 
when not more than n characters are searched.
If s2 is an empty string, s1 is returned; if s2 isn't found, a NULL pointer is returned.
Otherwise the first character of the first occurrence if s2 is returned.
*/

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] && n)
	{
		if (s1[i + j] == s2[j])
		{
			j++;
			n--;
		}
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