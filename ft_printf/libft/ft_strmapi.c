/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:39:39 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:42:48 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*new_str;
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
