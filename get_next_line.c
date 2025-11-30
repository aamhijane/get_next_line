/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:28:40 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/28 23:05:52 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*static_data;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
	{
		if (dst)
			free(dst);
		return (0);
	}
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
	return (ft_strlen(dst));
}

char	*ft_data_print(char *str)
{
	char	*data;
	size_t	len;

	if (!str)
		return (NULL);
	len = 0;
	data = NULL;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
	{
		len += 1;
		data = (char *)malloc(len);
		if (!data)
			return (NULL);
		ft_strlcpy(data, str, len);
	}
	return (data);
}

char	*ft_data_left(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
	{
		if (str[i + 1] != '\0')
			return (&str[i + 1]);
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	size;	
	size_t	i;	
	size_t	j;	
	size_t	len1;	
	size_t	len2;	

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		len1 = 0;
	else
		len1 = ft_strlen(str1);
	if (!str2)
		len2 = 0;
	else
		len2 = ft_strlen(str2);
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

char	*ft_data_read(int fd)
{
	char	*buffer;
	char	*buffer_tmp;
	char	*buffer_hold;
	ssize_t	bytes_read;

	buffer = NULL;
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	
	buffer_tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer_tmp)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = 0;
	while (!ft_data_left(buffer))
	{
		bytes_read = read(fd, buffer_tmp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer_tmp[bytes_read] = '\0';
		buffer_hold = buffer;
		buffer = ft_strjoin(buffer_hold, buffer_tmp);
		if (!buffer)
		{
			free(buffer_tmp);
			if (buffer_hold)
				free(buffer_hold);
			return (NULL);
		}
		if (buffer_hold)
			free(buffer_hold);
	}
	free(buffer_tmp);
	return (buffer);
}

void	ft_data_join(char *data, char *data_left)
{
	if (!data)
		return ;
	if (data_left)
	{
		if (!static_data)
			static_data = ft_strjoin(static_data, data_left);
		else
			static_data = ft_strjoin(static_data, data);
	}
}

void	get_next_line(int fd)
{
	char *data = ft_data_read(0);
	char *data_left = ft_data_left(data);
	char *data_print;


	data_print = NULL;
	ft_data_join(data, data_left); 
	data_print = ft_data_print(static_data);
	static_data += ft_strlen(data_print);


	printf("============================================");
	printf("DATA:\n");
	printf("[%s]\n", data);
	printf("============================================");
	printf("DATA PRINT (LINE):\n");
	printf("[%s]\n", data_print);
	printf("============================================");
	printf("STATIC DATA:\n");
	printf("[%s]\n", static_data);

	if (data_print)
		free(data_print);
	if (data)
		free(data);
}	

int	main(void)
{
	get_next_line(0);
	get_next_line(0);
	get_next_line(0);
	return (0);
}
