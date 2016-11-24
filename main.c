#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char 	**line;

	if (argc != 1)
		ft_putstr_fd(2, "error");
	fd = open(argv[1], O_RDONLY);
	get_next line(fd, &line);
	close(fd);
	return (0);
}
