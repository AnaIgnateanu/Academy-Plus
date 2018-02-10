#ifndef FILLIT_H
#define FILLIT_H

# define SIZE (COLUMNS + 1) * ROWS
# define MAX_TETRIMINOS 26
# define MIN_TETRIMINOS 1
# define ROWS 4
# define COLUMNS 4
# define MATRIX_MAX_SIZE 16

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct 	s_tetri
{
	struct s_tetri		*next;
	char				*tetri;
	unsigned char		letter;
	int					w;
	int					h;
	char				**shape;
}				t_tetri;

t_tetri 	*ft_fill(int fd, t_tetri *tetri);
void		ft_error(void);
t_tetri 	*ft_shape(t_tetri *tetri);
int			ft_process(t_tetri *tetri);
int			ft_solve(t_tetri* shape, int n);



#endif