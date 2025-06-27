/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:23:40 by clouden           #+#    #+#             */
/*   Updated: 2025/06/10 13:23:46 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_lengto(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str != '\n' && *str != '\0')
	{
		len++;
		str++;
	}
	if (*str == '\n')
		return (++len);
	return (len);
}

char	*ft_grow_line(t_buffer *s, char *next, int fd)
{
	char	*newmem;
	int		n;

	n = 0;
	s->len = ft_lengto(next) + ft_lengto(&s->buff[fd][s->b[fd]]);
	newmem = malloc(s->len + 1);
	if (newmem == NULL)
		return (NULL);
	ft_memset(newmem, 0, s->len + 1);
	if (next && next[0])
	{
		while (next[n])
		{
			newmem[n] = next[n];
			n++;
		}
		free(next);
		next = NULL;
	}
	return (newmem);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long long	pattern;
	int					blocks;
	int					remaining;
	int					i;

	blocks = n / 8;
	remaining = n % 8;
	pattern = (unsigned char)c;
	pattern |= pattern << 8;
	pattern |= pattern << 16;
	pattern |= pattern << 32;
	i = 0;
	while (i < blocks)
	{
		((unsigned long long *)s)[i] = pattern;
		i++;
	}
	i = 0;
	while (i < remaining)
	{
		((unsigned char *)s)[(blocks * 8) + i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}

int	ft_buffer_up(int fd, t_buffer *s)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_MAX)
		return (0);
	if (!s->buff[fd])
	{
		s->buff[fd] = malloc(BUFFER_SIZE + 1);
		s->b[fd] = 0;
		if (!s->buff[fd])
			return (0);
		s->buff[fd] = ft_memset(s->buff[fd], 0, BUFFER_SIZE + 1);
	}
	if (s->buff[fd] && (s->buff[fd][s->b[fd]] == 0 || s->b[fd] == 0))
	{
		s->b[fd] = 0;
		if (s->buff[fd][0])
			s->buff[fd] = ft_memset(s->buff[fd], 0, BUFFER_SIZE + 1);
		s->bytes = read(fd, s->buff[fd], BUFFER_SIZE);
	}
	return (1);
}
