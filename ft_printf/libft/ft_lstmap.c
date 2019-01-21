/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:14:14 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:18:08 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*head;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	if (lst == NULL || f == NULL)
		return (NULL);
	head = f(lst);
	new_lst = head;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = f(lst);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (head);
}
