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

# define FD_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strchr(char *s, char c);
size_t	ft_len(const char *str);
char	*ft_join(char *s1, char *s2);
char	*ft_line(char *s);
char	*ft_left(char *s);
char	*ft_read(int fd, char *s);
char	*get_next_line(int fd);
#endif
