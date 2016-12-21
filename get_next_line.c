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

static int		ft_str_to_line(char *str, char **line)
{
	char	*endline;

	endline = NULL;
	endline = ft_strchr(str, '\n');
	if (endline)
	{
		*line = ft_strdup(str);
		ft_strcpy(str, endline + 1);
		return (1);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		str = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char *str;
	char		*endline;
	char		*tmp;
	int			rd;

	str = NULL;
	endline = NULL;
	tmp = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	endline = ft_strchr(str, '\n');
	while (!endline)
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd == 0)
			return (ft_str_to_line(str, line));
		else if (rd < 0)
			return (-1);
		buff[rd] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
	}
	return (ft_str_to_line(str, line));
}
