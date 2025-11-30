/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:15:51 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/28 15:17:12 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

size_t	ft_len(const char *str);
size_t	ft_copy(char *dst, char *src, size_t size);
char	*ft_join(char *str1, char *str2);
char	*ft_read(int fd, char *storage);
int	ft_is_newline(char *storage);
char	*ft_line(char *data);
char	*ft_left(char *data);
#endif
