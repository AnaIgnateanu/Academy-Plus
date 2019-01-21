#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = (void *) malloc(size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, size);
	return (ptr);
}