/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:54:35 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:54:49 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = NULL;
	if (str != NULL)
	{
		substr = (char *)malloc(len + 1);
		if (substr == NULL)
			return (NULL);
		while (i < len)
		{
			substr[i] = str[start];
			start++;
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
