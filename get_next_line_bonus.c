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

#include "get_next_line_bonus.h"

char	*ft_nullout(t_buffer *s, char **next, int fd)
{
	if (s->buff[fd])
	{
		free(s->buff[fd]);
		s->buff[fd] = NULL;
	}
	if (next && *next)
	{
		free(*next);
		*next = NULL;
	}
	return (NULL);
}

int	ft_status(int fd, t_buffer *s, char **next)
{
	//printf("==Status fd==: %d  ||  ",fd);
	if (!ft_buffer_up(fd, s) || s->bytes < 1)
	{
		if (s->bytes == 0)
		{
			free(s->buff[fd]);
			s->buff[fd] = NULL;
			return (1);
		}
		ft_nullout(s, next, fd);
		return (-1);
	}
	*next = ft_grow_line(s, *next, fd);
	if (!*next)
	{
		ft_nullout(s, next, fd);
		return (-1);
	}
	//printf("X:");
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
	status = ft_status(fd, &s, &next);
	if (status != 0)
		return (next);
	while (s.buff[fd] && s.buff[fd][s.b[fd]] != '\n')
	{
		next[n] = s.buff[fd][s.b[fd]];
		s.b[fd]++;
		if (s.buff[fd][s.b[fd]] == '\0')
		{
			status = ft_status(fd, &s, &next);
			if (status != 0)
				return (next);
		}
		n++;
	}
	next[n] = s.buff[fd][s.b[fd]];
	return (s.b[fd]++, next);
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