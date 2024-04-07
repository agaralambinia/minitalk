/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:51:25 by defimova          #+#    #+#             */
/*   Updated: 2024/04/07 11:51:27 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	buf[fd] = read_remember(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = get_ln(buf[fd]);
	buf[fd] = buf_move(buf[fd]);
	return (line);
}

char	*read_remember(int fd, char *buf)
{
	char	*buffer;
	int		read_amt;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_amt = 1;
	while (!ft_strchr(buf, '\n') && read_amt > 0)
	{
		read_amt = read(fd, buffer, BUFFER_SIZE);
		if (read_amt == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_amt] = '\0';
		buf = ft_strjoin(buf, buffer);
	}
	free(buffer);
	return (buf);
}

char	*get_ln(char *buf)
{
	int		i;
	char	*ln;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	ln = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		ln[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		ln[i] = '\n';
	return (ln);
}

char	*buf_move(char *buf)
{
	int		i;
	int		j;
	char	*buf_new;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	buf_new = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf[i])
		buf_new[j++] = buf[i++];
	free(buf);
	return (buf_new);
}
