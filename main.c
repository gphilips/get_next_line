/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:10:47 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/02 19:47:53 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc != 2)
		ft_putendl_fd("error", 2);
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
			printf("line %d: %s\n", i++, line);
		close(fd);
	}
	return (0);
}
