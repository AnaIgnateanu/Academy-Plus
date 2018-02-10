#include "fillit.h"

char		**ft_read(int fd, char **arr, int *n)
{
	int 	ret;
	char	buf[SIZE + 1];
	int 	j;
	int 	i;
	
	i = 0;
	while ((ret = read(fd, buf, SIZE + 1)) >= SIZE)
	{	
		if ((arr[i] = (char*)malloc(sizeof(char) * (SIZE + 1))) == NULL)
			ft_error();
		j = 0;
		while (j < ret)
		{
			arr[i][j] = buf[j];
			j++;
		}
		arr[i][j] = '\0';
		i++;
		if (ret == 0)
			break;
		if (ret == -1 || ret < SIZE || i >= MAX_TETRIMINOS)
			return (NULL);
	}
	*n = i;
	return (arr);
}

t_tetri 	*ft_fill(int fd, t_tetri *tetri)
{
	char			**arr;
	int 			i;
	int 			n;
	unsigned char	c;
	t_tetri			*next_tetri;
	t_tetri			*current;

	i = 0;
	c = 'A';
	if ((arr = (char**)malloc(sizeof(char*) * MAX_TETRIMINOS)) == NULL)
		ft_error();
	arr = ft_read(fd, arr, &n);

	if (n == 0 || arr == NULL)
		ft_error();

	current = tetri;
	while (i < n)
	{
		current->tetri = (char *) malloc (sizeof(char) * SIZE);
		current->letter = c;
		ft_memcpy(current->tetri, arr[i], SIZE);

		if (i + 1 < n) 
		{
			next_tetri = malloc(sizeof *next_tetri);
			next_tetri->next = NULL;
			current->next = next_tetri;
		} 

		c++;
		i++;

		current = current->next;
	}

	return (tetri);
}

void	ft_coord(char *s, char *coord)
{
	int		i;

	i = 0;
	coord[0] = COLUMNS - 1;
	coord[1] = 0;
	coord[2] = ROWS - 1;
	coord[3] = 0;
	while (i < SIZE)
	{
		if (s[i] == '#')
		{
			if (i % 5 < coord[0])
				coord[0] = i % 5;
			if (i % 5 > coord[1])
				coord[1] = i % 5;
			if (i / 5 < coord[2])
				coord[2] = i / 5;
			if (i / 5 > coord[3])
				coord[3] = i / 5;
		}
		i++;
	}
}


t_tetri		*ft_shape(t_tetri *tetri)
{
	int		h;
	int		w;
	int		j;
	char	coord[4];
	t_tetri			*current;

	current = tetri;
	while (current)
	{
		ft_coord(current->tetri, coord);
		current->w = coord[1] - coord[0] + 1;
		current->h = coord[3] - coord[2] + 1;
		h = 0;
		current->shape = (char**)malloc(sizeof(char*) * 5);
		while (h < current->h)
		{
			w = 0;
			current->shape[h] = (char*)malloc(sizeof(char) * 5);
			while (w < current->w)
			{
				j = coord[0] + w + (coord[2] + h) * 5;
				current->shape[h][w] = current->tetri[j];
				w++;
			}
			h++;
		}
		current = current->next;
	}

	return (tetri);
}

int		ft_process(t_tetri *tetri)
{
	int		h;
	int		w;
	int		n;
	t_tetri			*current;

	n = 0;
	current = tetri;
	while (current != NULL)
	{
		h = 0;
		while (h < current->h)
		{
			w = 0;
			while (w < current->w)
			{
				if (current->shape[h][w] == '#')
					current->shape[h][w] = current->letter;
				w++;
			}
			h++;
		}
		n = n > (current->letter - 'A' + 1) ? n : (current->letter - 'A' + 1);
		current = current->next;
	}

	return (n);
}