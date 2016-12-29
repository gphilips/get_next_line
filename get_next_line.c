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

static char		*ft_str_to_endline(char *str, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(str);
	dest = ft_strnew(len);
	i = 0;
	while (str[i] != c && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

static int		ft_str_to_line(char *str, char **line)
{
	char	*endline;

	endline = ft_strchr(str, '\n');
	if (endline)
	{
		*line = ft_str_to_endline(str, '\n');
		ft_strcpy(str, endline + 1);
		return (1);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char *str = NULL;
	char		*endline;
	char		*tmp;
	int			rd;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	endline = ft_strchr(str, '\n');
	while ((rd = read(fd, buff, BUFF_SIZE)) && !endline)
	{
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
