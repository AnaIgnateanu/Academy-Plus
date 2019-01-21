#include "libft.h"

/*Returns a pointer to a new string which is a duplicate of the string str.
*/
char	*ft_strdup(const char *str)
{
	char	*dupl;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(str);
	dupl = (char *) malloc((l + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);
	while (str[i])
	{
		dupl[i] = str[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}