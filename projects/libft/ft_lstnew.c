#include "libft.h"

/*Allocates (with malloc(3)) and returns a “fresh” link. The
variables content and content_size of the new link are initialized
by copy of the parameters of the function. If the parameter
content is nul, the variable content is initialized to
NULL and the variable content_size is initialized to 0 even
if the parameter content_size isn’t. The variable next is
initialized to NULL. If the allocation fails, the function returns
NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	new_lst->content = malloc(content_size);
	if (content != NULL)
	{
		new_lst->content = ft_memmove(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	else
	{
		new_lst-> content = NULL;
		new_lst->content_size = 0;
	}
	new_lst->next = NULL;
	return (new_lst);
}