#include "libft.h"


/*Iterates a list lst and applies the function f to each link to
create a “fresh” list (using malloc(3)) resulting from the successive
applications of f. If the allocation fails, the function
returns NULL.*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
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