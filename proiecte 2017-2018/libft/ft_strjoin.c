#include "libft.h"

/*Allocates with malloc and returns a 'fresh' string nul-terminated, result of the concatenation of s1 and s2.
If the allocation fails the function returns NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (new_str == NULL)
			return (NULL);
		while (*s1)
		{
			new_str[i] = *s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			new_str[i] = *s2;
			s2++;
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}