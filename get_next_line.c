/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:22 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/17 18:59:15 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*retrieve_next_line(char *static_buffer)
{
	int		len;
	char	*r_buffer;
	int		nl_index;

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

static char	*load_next_line(int fd, char *static_buffer)
{
	char		*tmp;
	char static	*new_buffer;
	int			status;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	status = read(fd, tmp, BUFFER_SIZE);
	if (status <= 0)
	{
		free(tmp);
		return (static_buffer);
	}
	tmp[status] = '\0';
	new_buffer = ft_strjoin(static_buffer, tmp);
	if (!new_buffer)
		return (NULL);
	free(tmp);
	free(static_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;

	if (!static_buffer)
		static_buffer = malloc(BUFFER_SIZE + 1);
	if (!static_buffer)
		return (NULL);
	while (ft_strchr(static_buffer, '\n') == -1 && ft_strchr(static_buffer,
			'\0') == -1)
		static_buffer = load_next_line(fd, static_buffer);
	while (ft_strchr(static_buffer, '\n') == -1 && ft_strchr(static_buffer,
			'\0') == -1)
		static_buffer = retrieve_next_line(static_buffer);
	if (ft_strchr(static_buffer, '\n') == -1)
		return (static_buffer);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*static_buffer;
	char	*return_buffer;

	static_buffer = malloc(100000);
	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
