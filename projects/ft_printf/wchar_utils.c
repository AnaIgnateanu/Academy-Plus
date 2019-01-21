#include "ft_printf.h"

char	*ft_strmapf(char *str, char (*f)(char))
{
	char	*new_str;
	size_t	i;

	new_str = NULL;
	i = 0;
	if (str != NULL && f != NULL)
	{
		new_str = (char *)malloc(ft_strlen(str) + 1);
		if (new_str == NULL)
			return (NULL);
		while (i < ft_strlen(str))
		{
			new_str[i] = f(str[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	free(str);
	return (new_str);
}

char	*ft_strjoinf(char *s1, char *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

int					get_pos(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break;
		i++;
	}
	return (i);
}

