/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:22 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/17 15:49:40 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*retrieve_next_line(char *static_buffer)
{
	int		len;
	char	*r_buffer;
	int		i;
	int		nl_index;

	i = 0;
	nl_index = ft_strchr(static_buffer, '\n');
	if (nl_index == -1)
		len = ft_strlen(static_buffer);
	else
		len = nl_index + 1;
	r_buffer = malloc(len + 1);
	if (!r_buffer)
		return (NULL);
	ft_strlcpy(r_buffer, static_buffer, len + 1);
	if (static_buffer[len] == '\0')
		static_buffer[0] = '\0';
	else
		ft_strlcpy(static_buffer, static_buffer + len, ft_strlen(static_buffer
				+ len) + 1);
	return (r_buffer);
}

// char	*get_next_line(int fd)
// {
// 	static char	*static_buffer;
// 	char		*return_buffer;

// 	if (!static_buffer)
// 		static_buffer = malloc(BUFFER_SIZE + 1);
// 	if (!static_buffer)
// 		return (NULL);
// 	if (ft_strrchr(static_buffer, '\n'))
// 		return (return_next_line(static_buffer, return_buffer), return_buffer);
// 	else
// 	{
// 		while (!ft_strchr(static_buffer, '\n') || ft_strchr(static_buffer,
// 				'\n') != -1)
// 			load_next_line(fd, static_buffer);
// 	}
// 	if (ft_strchr(static_buffer, '\n'))
// 		retrieve_next_line(static_buffer, return_buffer);
// 	return ("");
// }

int	main(void)
{
	int		fd;
	char	*static_buffer;
	char	*return_buffer;

	static_buffer = malloc(100000);
	fd = open("text.txt", O_RDONLY);
	read(fd, static_buffer, 100000);
	return_buffer = retrieve_next_line(static_buffer);
	printf("%s", static_buffer);
	return (0);
}
