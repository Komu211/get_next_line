/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:06:44 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/19 17:55:19 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	int		i;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	jstr = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!jstr)
		return (NULL);
	while (i < len && s1[i] != '\0')
	{
		jstr[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		jstr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	jstr[i] = '\0';
	return (jstr);
}
t_fd_list	*ft_lstnew(int fd)
{
	t_fd_list	*new_lst;

	new_lst = malloc(sizeof(t_fd_list));
	if (!new_lst)
		return (NULL);
	new_lst->next = NULL;
	new_lst->buffer = malloc(BUFFER_SIZE + 1);
	if (!new_lst->buffer)
	{
		free(new_lst);
		return (NULL);
	}
	new_lst->fd = fd;
	return (new_lst);
}
