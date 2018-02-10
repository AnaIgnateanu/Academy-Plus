#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}



int		main(int argc, char **argv)
{
	int 		fd;
	t_tetri		*tetri;
	int 		n;

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" input_file\n");
		return (1);
	}
	tetri = (t_tetri*)malloc(sizeof(t_tetri));
	tetri = ft_shape(ft_fill((fd = open(argv[1], O_RDONLY)), tetri));
	n = ft_process(tetri);
	close(fd);

	printf("Solution= %d", ft_solve(tetri, n));

	return (0);
}