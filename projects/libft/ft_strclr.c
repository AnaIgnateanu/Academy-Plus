#include "libft.h"

/*Sets every character of the input string to the value '\0'.*/

void	ft_strclr(char *s)
{
	if (s != NULL)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
	
}