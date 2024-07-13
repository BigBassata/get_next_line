/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:37:05 by licohen           #+#    #+#             */
/*   Updated: 2024/07/13 14:50:00 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_rest(char *str, char *rest)
{
	int		i;
	char	*temp;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	temp = ft_substr(str, i, ft_strlen(str + i));
	free(rest);
	rest = temp;
	if (str && str[i])
		str[i] = '\0';
	return (rest);
}

char	*read_line(int fd, char *str)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
			{
				free(str);
				str = NULL;
			}
			break ;
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = rest;
	rest = NULL;
	str = read_line(fd, str);
	rest = fill_rest(str, rest);
	if (!str)
		free(rest);
	return (str);
}

// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }