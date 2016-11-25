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

static char	*ft_read_file(int fd, char *text)
{
	int		rd;
	char	buff[BUFF_SIZE + 1];
	int		i;

	i = 0;
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		text = ft_strjoin(text, buff);
	}
	return (text);
}

static char	*ft_get_line(char *text, char *line)
{
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i])
		i++;
	line = ft_strsub(text, 0, i);
	text = ft_strchr(text, '\n');
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char		*text;
	int				i;

	if (fd == -1 || !line)
		return (-1);
	if (!(text = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	text = ft_read_file(fd, text);
	i = 0;
	if (text[i] != '\0')
	{
		while (text[i] != '\n' && text[i])
		{
			*line = ft_get_line(text, *line);
			i++;
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
