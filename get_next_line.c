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

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*line;
	char	*left;
	char	*hold;
	size_t	len;

	storage = ft_read(fd, storage);
	if (!storage || !storage[0])
		return (NULL);
	line = ft_line(storage);
	left = ft_left(storage);
	hold = NULL;
	if (left && left[0])
	{
		len = ft_len(left); 
		hold = (char *)malloc(len + 1);
		if (!hold)
		{
			free(line);
			free(storage);
			storage = NULL;
			return (NULL);
		}
		ft_copy(hold, left, len + 1);
	}
	free(storage);
	storage = hold;
	return (line);
}	

int	main(void)
{
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	return (0);
}
