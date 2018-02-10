#include "fillit.h"

int		ft_shape_fits(t_tetri tetri, char **map, int mapSize, int x, int y)
{
	int i;
	int j;

	if (x + tetri.h > mapSize || y + tetri.w > mapSize)
		return (0);
	i = 0;
	while (i < tetri.h)
	{
		j = 0;
		while (j < tetri.w)
		{
			if (map[x + i][y + j] != '.' && tetri.shape[i][j] != '.') 
				return (0);
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
			if (fill == 1) {
				if (tetri.shape[i][j] != '.') {
					map[x + i][y + j] = tetri.shape[i][j];
				}
			}
			else if (tetri.shape[i][j] != '.') {
				map[x + i][y + j] = '.';
			}
			j++;
		}
		i++;
	}

	return (1);
}

int		ft_solve_size(t_tetri* shape, int *visited, char **map, int size, int count, int n)  
{
	int x; 
	int y;
		
	if (shape == NULL) {
		return (0);
	}
	// else if (shape->next == NULL) {
	// 	return (1);
	// }

	// ft_print(map, size);

	x = 0;
	while (x < size) 
	{
		y = 0;
		while (y < size) 
		{
				// usleep(500000);
			// if we can add the shape starting from the current point
			if (!visited[shape->letter - 'A'] && ft_shape_fits(*shape, map, size, x, y)) 
			{
				// make move
				ft_shape_fill(*shape, map, x, y, 1);
				visited[shape->letter - 'A'] = 1;
				count++;
				
				if (count == n) {
					printf("%d %d\n", count, n);
					ft_print(map, size);
					return (1);
				}

				int solutuion = ft_solve_size(shape->next, visited, map, size, count, n);
				if (solutuion != 0) 
					return 1;

				// backtracking 
				ft_shape_fill(*shape, map, x, y, 0);
				visited[shape->letter - 'A'] = 0;
				count--;
			} 
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
	char	**map;
	int		*visited;

	// start off with the minimum matrix size
	size = 2;
	while (size * size < n * 4)
		size++;

	// allocate resource
	i = 0;
	visited = (int *)malloc(sizeof(int) * n);
	ft_bzero(visited, n);
	map = (char**)malloc(sizeof(char*) * (MATRIX_MAX_SIZE + 1));
	while (i < MATRIX_MAX_SIZE)
	{
		map[i] = (char*)malloc(sizeof(char) * (MATRIX_MAX_SIZE + 1));
		ft_setdot(map[i], sizeof(char) * MATRIX_MAX_SIZE);
		i++;
	}

	// solve for the current size
	printf("n = %d\n", size);
	while (!ft_solve_size(shape, visited, map, size, 0, n) && size < min(n * 4, MATRIX_MAX_SIZE))
	{
		ft_bzero(visited, n);
		i = 0;
		while (i < MATRIX_MAX_SIZE)
		{
			ft_setdot(map[i], sizeof(char) * MATRIX_MAX_SIZE);
			i++;
		}
		size++;
		printf("n = %d\n", size);
	}
	return (size == MATRIX_MAX_SIZE + 1 ? 0 : size);
}



