/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:22 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/16 15:49:40 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			fd_pos;
	static char	*buffer;

	fd_pos = 0;
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) && get_linesep_pos(buffer) >= 0)
	{
		fd_pos = write(1, buffer, get_linesep_pos(buffer));
		if (fd_pos == -1 || fd_pos == 0)
			return (NULL);
	}
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
