/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:29:06 by licohen           #+#    #+#             */
/*   Updated: 2024/06/15 15:06:00 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*join;

// 	i = 0;
// 	j = 0;
// 	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//     if (!join)
//         return (NULL);
// 	while (s1[i])
// 	{
// 		join[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		join[i] = s2[j];
// 		i++;
// 		j++;
// 	}
//     join[i] = '\0';
// 	return (join);
// }

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = ",World";
	char *s_new;

	s_new = ft_strjoin(s1, s2);
	printf("%s\n", s_new);
}
