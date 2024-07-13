/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:50:03 by user              #+#    #+#             */
/*   Updated: 2024/07/13 14:48:14 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*rest[1024] = {0};
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = rest[fd];
	rest[fd] = NULL;
	str = read_line(fd, str);
	rest[fd] = fill_rest(str, rest[fd]);
	if (!str)
		free(rest[fd]);
	return (str);
}

// int main()
// {
//     int fd1, fd2, fd3;
//     char *line1, *line2, *line3;
//     int tour = 1;

//     fd1 = open("test1.txt", O_RDONLY);
//     fd2 = open("test2.txt", O_RDONLY);
//     fd3 = open("test3.txt", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0)
//     {
//         printf("Erreur lors de l'ouverture des fichiers\n");
//         return 1;
//     }

//     line1 = get_next_line(fd1);
//     line2 = get_next_line(fd2);
//     line3 = get_next_line(fd3);

//     while (line1 || line2 || line3)
//     {
//         printf("--- Tour %d ---\n", tour);

//         if (line1)
//         {
//             printf("Fichier 1: %s", line1);
//             free(line1);
//             line1 = get_next_line(fd1);
//         }
//         else
//             printf("Fichier 1: fin de fichier\n");

//         if (line2)
//         {
//             printf("Fichier 2: %s", line2);
//             free(line2);
//             line2 = get_next_line(fd2);
//         }
//         else
//             printf("Fichier 2: fin de fichier\n");

//         if (line3)
//         {
//             printf("Fichier 3: %s", line3);
//             free(line3);
//             line3 = get_next_line(fd3);
//         }
//         else
//             printf("Fichier 3: fin de fichier\n");

//         printf("\n");
//         tour++;
//     }

//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return 0;
// }