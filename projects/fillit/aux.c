#include "fillit.h"

void	ft_setdot(void *s, size_t n)
{
	ft_memset((void *)s, '.', (size_t)n);
}

void	ft_print(char **arr, int n) 
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			printf("%c ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}