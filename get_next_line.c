/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:52:01 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/24 19:59:00 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_linelen(char *buff)
{
	int		i;

	while (buff[i] && buff[i] == '\n')
		i++;
	return (i);
}

static char	ft_read_file(int fd, char **line)
{
	int		rd;
	char	buff[BUFF_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (fd < 0)
		return (0);
	while ((rd = read(fd, buff, BUFF_SIZE)) && buff[i] != '\n')
	{
		line[j] = buff[i];
		i++;
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char		*rest;
	
	if (fd == -1)
		return (1);
	if (!(line = (char**)malloc(sizeof(char))))
		return (NULL);
	line = ft_read_file(fd, (char**)(line));

	if (!(rest = (char*)malloc(sizeof(char) *linelen + 1)))
		return (NULL);
}
