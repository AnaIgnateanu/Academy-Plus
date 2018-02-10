#include "libft.h"

/*Allocates with malloc and returns a copy if the string given as argument 
without whitespaces (' ', '\n', '\t') at the beginning or at the end of the string.
If s has no whitespaces at the beginning or at the end, the function returns a copy of s.
If the allocation fails the function returns NULL.
*/

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		i;
	int		l;
	int		j;

	new_str = NULL;
	i = 0;
	j = 0;
	if (s != NULL)
	{
		l = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while ((s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t') && 
			l >= 0 && i <= l)
			l--;
		new_str = (char *)malloc(l - i + 1);
		if (new_str == NULL)
			return (NULL);
		while (i < l)
			new_str[j++] = s[i++];
		new_str[j] = '\0';
	}
	return (new_str);
}
