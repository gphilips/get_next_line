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

static char	*ft_read_file(int fd, char *rest)
{
	int		rd;
	char	buff[BUFF_SIZE + 1];
	int		i;

	i = 0;
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	return (rest);
}

int			get_next_line(const int fd, char **line)
{
	static char		*rest;
	int				i;

	if (fd == -1 || !line)
		return (-1);
	if (!(rest = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	rest = ft_read_file(fd, rest);
	i = 0;
	if (rest[i] != '\0')
	{
		while (rest[i] != '\n' && rest[i])
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strsub(rest, 0, i);
			rest = &rest[i + 1];
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
