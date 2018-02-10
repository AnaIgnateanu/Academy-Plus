/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:18:27 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:19:19 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	new_lst->content = malloc(content_size);
	if (content != NULL)
	{
		if ((new_lst->content = malloc(content_size)) == NULL)
			return (NULL);
		new_lst->content = ft_memmove(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	else
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	new_lst->next = NULL;
	return (new_lst);
}
