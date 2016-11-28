/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:52:01 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/25 17:09:46 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(int fd, char **str)
{
	char	*buff;
	char	*newline;
	int		rd_size;

	if (!(buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	newline = NULL;
	rd_size = read(fd, buff, BUFF_SIZE);
	if (rd_size > 0)
	{
		buff[rd_size] = '\0';
		newline = ft_strjoin(*str, buff);
		if (!newline)
			return (-1);
		ft_strdel(str);
		free(buff);
		*str = newline;
	}
	return (rd_size);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	char		*endline;
	int			rd;

	if (!str)
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (-1);
	}
	endline = ft_strchr(str, '\n');
	while (!endline)
	{
		rd = ft_read(fd, &str);
		 if (rd == 0)
		{
			endline = ft_strchr(str, '\0');
			if (str == endline)
			return (0);
		}
		else if (rd < 0)
			return (-1);
		else
			endline = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, endline - str);
	if (!(*line))
		return (-1);
	free(str);
	str = ft_strdup(endline + 1);
	return (1);
}
