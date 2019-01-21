/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:37:30 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:38:08 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
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
	return (new_str);
}
