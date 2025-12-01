/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:58:39 by ayamhija          #+#    #+#             */
/*   Updated: 2025/12/01 17:58:42 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*storage[FD_MAX];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = ft_read(fd, storage[fd]);
	if (!storage[fd] || !storage[fd][0])
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	line = ft_line(storage[fd]);
	tmp = ft_left(storage[fd]);
	free(storage[fd]);
	storage[fd] = tmp;
	return (line);
}
