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

	i = 0;
	c = 'A';
	if ((arr = (char**)malloc(sizeof(char*) * MAX_TETRIMINOS)) == NULL)
		ft_error();
	arr = ft_read(fd, arr, &n);
	if (n == 0 || arr == NULL)
		ft_error();
	while (i < n)
	{
		tetri[i].tetri = ft_memalloc(SIZE + 1);
		tetri[i].tetri = ft_memcpy(tetri[i].tetri, arr[i], SIZE);
		tetri[i].letter = c;
		tetri[i].next = &(tetri[i + 1]); 
		c++;
		i++;
	}
	tetri[i - 1].next = NULL;
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
	int		i;
	int		h;
	int		w;
	int		j;
	char	coord[4];

	i = 0;
	while (tetri[i].tetri != NULL)
	{
		ft_coord(tetri[i].tetri, coord);
		tetri[i].w = coord[1] - coord[0] + 1;
		tetri[i].h = coord[3] - coord[2] + 1;
		h = 0;
		tetri[i].shape = (char**)malloc(sizeof(char*) * 5);
		while (h < tetri[i].h)
		{
			w = 0;
			tetri[i].shape[h] = (char*)malloc(sizeof(char) * 5);
			while (w < tetri[i].w)
			{
				j = coord[0] + w + (coord[2] + h) * 5;
				tetri[i].shape[h][w] = tetri[i].tetri[j];
				w++;
			}
			h++;
		}
		i++;
	}
	return (tetri);
}

int		ft_process(t_tetri *tetri)
{
	int 	i;
	int		h;
	int		w;
	int		n;

	i = 0;
	n = 0;
	while (tetri[i].shape != NULL)
	{
		h = 0;
		while (h < tetri[i].h)
		{
			w = 0;
			while (w < tetri[i].w)
			{
				if (tetri[i].shape[h][w] == '#')
					tetri[i].shape[h][w] = tetri[i].letter;
				printf("%c ", tetri[i].shape[h][w]);
				w++;
			}
			h++;
			printf("\n");
		}
		printf("\n");
		n = n > (tetri[i].letter - 'A' + 1) ? n : (tetri[i].letter - 'A' + 1);
		i++;
	}
	fflush(stdout);
	return (n);
}