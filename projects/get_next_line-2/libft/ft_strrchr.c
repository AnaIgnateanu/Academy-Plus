/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:43:06 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:43:52 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = (int)ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (unsigned char)c)
		{
			return ((char *)str + len);
		}
		len--;
	}
	return (NULL);
}
