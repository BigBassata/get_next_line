/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:27:58 by licohen           #+#    #+#             */
/*   Updated: 2024/06/24 15:29:10 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *s);
char	*ft_get_rest(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_read(int fd, char *s);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(char *s);

#endif