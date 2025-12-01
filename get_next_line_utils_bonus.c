/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:59:01 by ayamhija          #+#    #+#             */
/*   Updated: 2025/12/01 17:59:03 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	ft_strchr(char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = malloc(ft_len(s1) + ft_len(s2) + 1);
	if (!result)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_line(char *s)
{
	char	*line;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = s[i];
	line[i] = '\0';
	return (line);
}

char	*ft_left(char *s)
{
	char	*left;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (!s[i])
		return (NULL);
	left = malloc(ft_len(&s[i]) + 1);
	if (!left)
		return (NULL);
	j = 0;
	while (s[i])
		left[j++] = s[i++];
	left[j] = '\0';
	return (left);
}
