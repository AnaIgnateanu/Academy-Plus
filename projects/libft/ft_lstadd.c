#include "libft.h"

/*Adds the element new at the beginning of the list.*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	*alst = new;
	new->next = tmp;
}