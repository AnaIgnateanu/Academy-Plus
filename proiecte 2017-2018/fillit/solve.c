#include "fillit.h"

int		ft_shape_fits(t_tetri* tetri, char **map, int mapSize, int x, int y)
{
	int i;
	int j;

	if (x + tetri->h > mapSize || y + tetri->w > mapSize)
		return (0);
	i = 0;
	while (i < tetri->h)
	{
		j = 0;
		while (j < tetri->w)
		{
			if (map[x + i][y + j] != 0 && tetri->shape[i][j] != 0) 
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_shape_fill(t_tetri tetri, char **map, int x, int y, int fill)
{
	int i;
	int j;

	i = 0;	
	while (i < tetri.h)
	{
		j = 0;
		while (j < tetri.w)
		{
			if (tetri.shape[i][j] != 0)
			{
				if (fill == 1)
					map[x + i][y + j] = tetri.letter;
				else
					map[x + i][y + j] = 0;
				printf("%d %d\n", x, y);
			} 
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_solve_size(t_tetri* shape, int *visited, char **map, int size)  
{
	int x; 
	int y;

	x = 0;
	while (x < size) 
	{
		y = 0;
		while (y < size) 
		{
			// if we can add the shape starting from the current point
			if (!visited[shape->letter - 'A'] && ft_shape_fits(shape, map, size, x, y)) 
			{
				ft_shape_fill(*shape, map, x, y, 1);
				visited[shape->letter - 'A'] = 1;
				// are we done ?
				if (shape->next == NULL)
					return (1);
				ft_solve_size(shape->next, visited, map, size);
				ft_shape_fill(*shape, map, x, y, 0);
				visited[shape->letter - 'A'] = 0;
			} 
			//printf("%d %d %d\n", x, y, size);
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_solve(t_tetri* shape, int n) 
{
	int 	i;
	int		size;
	char**  map;
	int* 	visited;

	// start off with the minimum matrix size
	size = 2;
	while (size * size < n * 4)
		size++;

	// allocate resource
	i = 0;
	visited = (int *)malloc(sizeof(int) * n);
	ft_bzero(visited, n);
	map = (char**)malloc(sizeof(char*) * (MATRIX_MAX_SIZE + 1));
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * (MATRIX_MAX_SIZE + 1));
		ft_bzero(map[i], sizeof(char) * MATRIX_MAX_SIZE);
		i++;
	}

	// solve for the current size
	while (!ft_solve_size(shape, visited, map, size) && size <= MATRIX_MAX_SIZE)
	{
		ft_bzero(map, sizeof(char) * MATRIX_MAX_SIZE * MATRIX_MAX_SIZE);
		size++;
	}
	return (size == MATRIX_MAX_SIZE + 1 ? 0 : size);
}



