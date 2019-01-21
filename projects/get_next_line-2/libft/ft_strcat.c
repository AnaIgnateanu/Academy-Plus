/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:29:02 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:29:08 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s1);
	while (s2[i])
	{
		s1[l + i] = s2[i];
		i++;
	}
	s1[l + i] = '\0';
	return (s1);
}
