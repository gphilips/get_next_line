/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:52:01 by gphilips          #+#    #+#             */
/*   Updated: 2016/12/02 19:22:48 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(int fd, char **str)
{
	char	buff[BUFF_SIZE + 1];
	int		rd_size;
	char	*tmp;

	rd_size = read(fd, buff, BUFF_SIZE);
	if (rd_size > 0)
	{
		buff[rd_size] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
	}
	else if (rd_size < 0)
		return (-1);
	else
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *str;
	char		*endline;
	int			rd;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!str)
	{
		if (!(str = ft_strnew(0)))
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
	endline = ft_strdup(endline + 1);
	free(str);
	str = endline;
	return (1);
}
