/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:22 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/19 16:28:05 by kmuhlbau         ###   ########.fr       */
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

static char	*load_next_set(int fd, char *static_buffer, int *status)
{
	char	*tmp;
	char	*new_buffer;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
	{
		free(static_buffer);
		return (NULL);
	}
	*status = read(fd, tmp, BUFFER_SIZE);
	if (*status <= 0)
	{
		free(tmp);
		if (*status < 0 || static_buffer[0] == '\0')
			return (free(static_buffer), NULL);
		return (static_buffer);
	}
	tmp[*status] = '\0';
	new_buffer = ft_strjoin(static_buffer, tmp);
	free(tmp);
	free(static_buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

static char	*retrieve_and_cleanup(char **static_buffer)
{
	char	*line;

	if ((*static_buffer)[0] == '\0')
	{
		free(*static_buffer);
		*static_buffer = NULL;
		return (NULL);
	}
	line = retrieve_next_line(*static_buffer);
	if (!line)
	{
		free(*static_buffer);
		*static_buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;
	int			status;

	status = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!static_buffer)
	{
		static_buffer = malloc(1);
		if (!static_buffer)
			return (NULL);
		static_buffer[0] = '\0';
	}
	while (ft_strchr(static_buffer, '\n') == -1 && status > 0)
	{
		static_buffer = load_next_set(fd, static_buffer, &status);
		if (!static_buffer || status < 0)
			return (NULL);
	}
	line = retrieve_and_cleanup(&static_buffer);
	return (line);
}
