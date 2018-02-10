/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:02:18 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 18:02:49 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dupl;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(str);
	dupl = (char *)malloc((l + 1) * sizeof(char));
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
