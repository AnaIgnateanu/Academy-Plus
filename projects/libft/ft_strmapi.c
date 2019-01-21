#include "libft.h"

/*Applies the function f to each character of the string given as argument
by giving its index to create a 'fresh' new string (with malloc)
resulting from successive applications of f.
*/

char 	*ft_strmapi(char const *str, char(*f)(unsigned int, char))
{
	char 			*new_str;
	unsigned int	i;

	new_str = NULL;
	i = 0;
	if (str != NULL && f != NULL)
	{
		new_str = (char *)malloc(ft_strlen(str) + 1);
		if (new_str == NULL)
			return (NULL);
		while (i < ft_strlen(str))
		{
			new_str[i] = f(i, str[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}