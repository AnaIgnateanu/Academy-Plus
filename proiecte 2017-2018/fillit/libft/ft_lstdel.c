/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanolac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:12:43 by amanolac          #+#    #+#             */
/*   Updated: 2017/12/18 17:12:52 by amanolac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	if (*alst != NULL && del != NULL)
	{
		while (tmp)
		{
			next = tmp->next;
			del((tmp)->content, (tmp)->content_size);
			free(tmp);
			tmp = next;;
		}
		*alst = NULL;
	}
}
