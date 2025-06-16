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

#include "get_next_line.h"

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

char	*ft_grow_line(t_buffer *s)
{
	char	*newmem;

	if (s->next && s->next[s->n] == '\n')
	{
		s->n = 0;
		free(s->next);
		s->next = NULL;
	}
	s->len = ft_lengto(s->next) + ft_lengto(&s->buff[s->b]);
	newmem = malloc(s->len + 1);
	if (newmem == NULL)
		return (NULL);
	newmem = ft_memset(newmem, 0, s->len + 1);
	if (s->next && s->next[0])
	{
		s->n = 0;
		while (s->next[s->n])
		{
			newmem[s->n] = s->next[s->n];
			s->n++;
		}
		free(s->next);
		s->next = NULL;
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

int ft_buffer_up(int fd, t_buffer *s)
{	
	if (BUFFER_SIZE <= 0 || fd < 0)
    	return (0);
	if (s->eof == 1)
	{
		free(s->buff);
		s->buff = NULL;
		free(s->next);
		s->next = NULL;
		return (0);
	}
	if (!s->buff)
	{
		s->buff = malloc(BUFFER_SIZE + 1);
		s->b = 0;
		if (!s->buff)
			return (0);
		s->buff = ft_memset(s->buff, 0, BUFFER_SIZE + 1);
	}
	if (s->buff[s->b] == 0 || s->b == 0)
	{
		s->b = 0;
		s->buff = ft_memset(s->buff, 0, BUFFER_SIZE + 1);
		s->bytes = read(fd, s->buff, BUFFER_SIZE);
	}
	return (1);
}


char	*ft_end(t_buffer *s)
{
	if (s->eof == 1)
	{
		free(s->buff);
		s->buff = NULL;
		free(s->next);
		s->next = NULL;
		return (NULL);
	}
	s->eof = 1;
	free(s->buff);
	s->buff = NULL;
	if (s->next && !s->next[0])
	{
		free(s->next);
		s->next = NULL;
	}
	return (s->next);
}
/*
int ft_buffer_up(int fd, t_buffer *s)
{	
	if (BUFFER_SIZE <= 0 || fd < 0)
    	return (0);
	if (s->eof == 1)
		return (ft_end(s));
	if (!s->buff)
	{
		s->buff = malloc(BUFFER_SIZE + 1);
		s->b = 0;
		if (!s->buff)
			return (0);
	}
	if (s->buff[s->b] == 0 || s->b == 0)
	{
		s->b = 0;
		s->buff = ft_memset(s->buff, 0, BUFFER_SIZE + 1);
		s->bytes = read(fd, s->buff, BUFFER_SIZE);
	}
	if (!s->bytes)
		return(ft_end(s));
	return (1);
}


char	*ft_end(t_buffer *s)
{
	if (s->eof == 1)
	{
		if (s->buff)
		{
			free(s->buff);
			s->buff = NULL;
		}
		if (s->next)
		{
			free(s->next);
			s->next = NULL;
		}
		return (NULL);
	}
	s->eof = 1;
	free(s->buff);
	s->buff = NULL;
	if (s->next && !s->next[0])
	{
		free(s->next);
		s->next = NULL;
	}
	return (s->next);
}

*/