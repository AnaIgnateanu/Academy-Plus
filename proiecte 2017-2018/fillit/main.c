#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}



int		main(int argc, char **argv)
{
	int 		fd;
	t_tetri		tetri[MAX_TETRIMINOS + 1];
	int 		n;

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" input_file\n");
		return (1);
	}
	ft_bzero(tetri, sizeof(t_tetri) * (MAX_TETRIMINOS + 1));
	n = ft_process(ft_shape(ft_fill((fd = open(argv[1], O_RDONLY)), tetri)));
	close(fd);

	ft_solve(tetri, n);

	return (0);
}