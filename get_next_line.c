/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:21:36 by clouden           #+#    #+#             */
/*   Updated: 2025/06/12 12:40:06 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nullout(t_buffer *s, char **next)
{
	if (s->buff)
	{
		free(s->buff);
		s->buff = NULL;
	}
	if (next && *next)
	{
		free(*next);
		*next = NULL;
	}
	return (NULL);
}

int	ft_phases(int fd, t_buffer *s, char **next)
{
	if (!ft_buffer_up(fd, s) || s->bytes < 1)
	{
		if (s->bytes == 0)
		{
			free(s->buff);
			s->buff = NULL;
			return (1);
		}
		ft_nullout(s, next);
		return (-1);
	}
	*next = ft_grow_line(s, *next);
	if (!*next)
	{
		ft_nullout(s, next);
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer	s;
	char			*next;
	int				n;
	int				status;

	next = NULL;
	n = 0;
	status = ft_phases(fd, &s, &next);
	if (status != 0)
		return (next);
	while (s.buff && s.buff[s.b] && s.buff[s.b] != '\n')
	{
		next[n] = s.buff[s.b];
		s.b++;
		if (s.buff[s.b] == '\0')
		{
			status = ft_phases(fd, &s, &next);
			if (status != 0)
				return (next);
		}
		n++;
	}
	if (s.buff[s.b] == '\n')
		next[n] = s.buff[s.b];
	return (++s.b, next);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*newln;
// 	fd = open("read.txt", O_RDONLY);
// 	while ((newln = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", newln);	
// 		free(newln);
// 	}
// 	close(fd);
// 	return (0);
// }