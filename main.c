#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char 	*line;

	if (argc != 2)
		ft_putendl_fd("error", 2);
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			write(1, line, ft_strlen(line));
		close(fd);
	}
	return (0);
}
