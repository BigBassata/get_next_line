/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:28:39 by licohen           #+#    #+#             */
/*   Updated: 2024/06/19 18:53:50 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_until_newline(int fd, char *stash)
{   
    char buffer[BUFFER_SIZE + 1];
    char *new_stash;
    ssize_t b_read;
    
    b_read = 1;
    while (b_read > 0)
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        if (b_read == -1)
            return (NULL);
        // if (b_read == 0)
        //     break ;
        buffer[b_read] = '\0';
        new_stash = stash;
        stash = ft_strjoin(new_stash, buffer);
        free(new_stash);

        if (ft_strchr(buffer, '\n'))
        break ;
    }
    return (stash);
    
}

char *get_next_line(int fd)
{
    static char *stash = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    line = read_until_newline(fd, stash);
    
    return (line);
}

// void	read_file(const char *file)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(file, O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("ligne: %s\n", line);
// 	}
// 	free(line);
// 	close(fd);
// }

// int	main(void)
// {
// 	read_file("fichier.txt");
// } 