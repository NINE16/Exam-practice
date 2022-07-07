/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:27:36 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/03 11:47:58 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	line = (char *) malloc (1);
	line[0] = '\0';
	while (read(fd, &buf, 1) > 0)
	{
		line = ft_strjoin(line, buf);
		if (buf == '\n')
			break ;
	}
	while (line[i])
		i++;
	if (i == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
