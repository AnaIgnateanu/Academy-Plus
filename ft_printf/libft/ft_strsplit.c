/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:44:36 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 18:09:21 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int count;

	count = 0;
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

static	char	*malloc_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
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

char			**ft_strsplit(char const *str, char c)
{
	int		words;
	int		i;
	char	**tab;

	tab = NULL;
	if (str != NULL)
	{
		words = count_words(str, c);
		i = 0;
		if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
			return (NULL);
		while (*str)
		{
			while (*str && *str == c)
				str++;
			if (*str && *str != c)
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
