/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:28:40 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/30 11:28:14 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *s)
{
	char	*buf;
	char	*tmp;
	ssize_t	b;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	b = 1;
	while (b > 0 && !ft_strchr(s, '\n'))
	{
		b = read(fd, buf, BUFFER_SIZE);
		if (b < 0)
			return (free(buf), free(s), NULL);
		buf[b] = '\0';
		tmp = s;
		s = ft_join(tmp, buf);
		free(tmp);
	}
	return (free(buf), s);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (!storage || !storage[0])
		return (free(storage), storage = NULL, NULL);
	line = ft_line(storage);
	tmp = ft_left(storage);
	free(storage);
	storage = tmp;
	return (line);
}
