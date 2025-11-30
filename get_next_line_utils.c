/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:58:44 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/30 11:08:52 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_copy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_len(dst));
}

char	*ft_join(char *str1, char *str2)
{
	char	*result;
	size_t	i;	
	size_t	j;	
	size_t	len1;	
	size_t	len2;	

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		len1 = 0;
	else
		len1 = ft_len(str1);
	if (!str2)
		len2 = 0;
	else
		len2 = ft_len(str2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
	{
		if (str1)
			free(str1);
		return (NULL);
	}
	i = 0;
	while (len1 > 0 && str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	j = 0;
	while (len2 > 0 && str2[j])
	{
		result[i + j] = str2[j];
		j++;
	}
	result[len1 + len2] = '\0';
	return (result);
}	

char	*ft_read(int fd, char *storage)
{
	char	*buffer_tmp;
	char	*buffer_hold;
	ssize_t	bytes_read;

	if (!storage)
	{
		storage = (char *)malloc(1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	buffer_hold = NULL;
	buffer_tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer_tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_is_newline(storage))
	{
		bytes_read = read(fd, buffer_tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer_tmp);
			free(storage);
			return (NULL);
		}
		buffer_tmp[bytes_read] = '\0';
		buffer_hold = storage;
		storage = ft_join(buffer_hold, buffer_tmp);
		free(buffer_hold);
		if (!storage)
		{
			free(buffer_tmp);
			return (NULL);
		}
	}
	free(buffer_tmp);
	return (storage);
}

int	ft_is_newline(char *storage)
{
	size_t	i;

	if (!storage)
		return (0);
	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *data)
{
	char	*line;
	size_t	len;

	if (!data)
		return (NULL);
	len = 0;
	line = NULL;
	while (data[len])
	{
		if (data[len] == '\n')
			break;
		len++;
	}
	if (data[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_copy(line, data, len + 1);
	return (line);
}

char	*ft_left(char *data)
{
	char	*line;

	if (!data)
		return (NULL);
	line = ft_line(data);
	if (!line)
		return (NULL);
	return &data[ft_len(line)];
}
