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

char	*ft_phase_ctrl(int fd, t_buffer *s)
{
	if (s->eof == 1)
		return (ft_end(s));
	if (!ft_buffer_up(fd, s))
		return (NULL);
	if (!s->bytes)
		return (ft_end(s));
	s->next = ft_grow_line(s);
	if (!s->next)
		return (NULL);
	return (s->next);
}

char	*ft_nullout(t_buffer *s, char **out)
{
	if (s->buff)
	{
		free(s->buff);
		s->buff = NULL;
	}
	if (s->next)
	{
		free(s->buff);
		s->next = NULL;
	}
	if (out && *out)
	{
		free(*out);
		*out = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_buffer	s;
	char			*out;

	out = NULL;
	if (s.eof == 1)
	{
		ft_end(&s);
		if (s.next)
		{
			out = strdup(s.next);
			return (out);
		}
		else
			return (ft_nullout(&s, &out));
	}
	if (!ft_buffer_up(fd, &s))
		return (ft_nullout(&s, &out));
	if (s.bytes == 0)
	{
		ft_end(&s);
		if (s.next)
		{
			out = strdup(s.next);
			return (out);
		}
		else
			return (ft_nullout(&s, &out));
	}
	if (s.bytes == -1)
		return (ft_nullout(&s, &out));
	s.next = ft_grow_line(&s);
	if (!s.next)
		return (ft_nullout(&s, &out));
	while (s.buff && s.buff[s.b] != '\n')
	{
		s.next[s.n] = s.buff[s.b];
		s.b++;
		if (s.buff[s.b] == '\0')
		{
			if (!ft_buffer_up(fd, &s))
				return (ft_nullout(&s, &out));
			if (!s.bytes)
			{
				ft_end(&s);
				if (s.next)
				{
					out = strdup(s.next);
					return (out);
				}
				else
					return (ft_nullout(&s, &out));
			}
			s.next = ft_grow_line(&s);
			if (!s.next)
				return (ft_nullout(&s, &out));
			s.n--;
		}
		s.n++;
	}
	s.next[s.n] = s.buff[s.b];
	s.b++;
	out = strdup(s.next);
	return (out);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*newln;
// 	fd = open("read.txt", O_RDONLY);
// 	while ((newln = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", newln);	
// 	}
// 	free(newln);
// 	close(fd);
// 	return (0);
// }
