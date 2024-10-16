/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:20:38 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/16 15:29:58 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_linesep_pos(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\n')
		i++;
	if (c[i] != '\n')
		return (-1);
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size * sizeof(char));
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (unsigned char)0;
		i++;
	}
}
