/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:00:46 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 18:01:00 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
