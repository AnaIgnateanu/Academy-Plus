#include "libft.h"

/*Allocates (with malloc(3)) and returns an array of “fresh”
strings (all ending with ’\0’, including the array itself) obtained
by spliting s using the character c as a delimiter.
If the allocation fails the function returns NULL. Example
: ft_strsplit("*hello*fellow***students*", ’*’) returns
the array ["hello", "fellow", "students"].
*/

static int		count_words(const char *str, char c)
{
	int count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static	char 	*malloc_word(const char *str, char c)
{
	char *word;
	int i =0;

	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char 	**ft_strsplit(char const *str, char c)
{
	int		words;
	int		i;
	char 	**tab;

	tab = NULL;
	if (str != NULL)
	{
		words = count_words(str, c);
		i = 0;
		tab = (char **)malloc(sizeof(char *) * (words + 1));
		if (tab == NULL)
			return (NULL);
		while (*str)
		{
			while (*str && *str == c)
				str++;
			if(*str && *str != c)
			{
				tab[i++] = malloc_word(str, c);
				while (*str && *str != c)
					str++;
			}
		}
		tab[i] = NULL;
	}
	return (tab);
}