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

char	*get_next_line(int fd)
{
	static t_buffer	s;
	char 			*kk;

	if (s.eof == 1)
	{
		ft_end(&s);
		if (s.next)
			kk = strdup(s.next);
		else
			kk = NULL;
		return (kk);
	}
	if(!ft_buffer_up(fd, &s))
		return (NULL);
	if (!s.bytes)
	{
		ft_end(&s);
		if (s.next)
			kk = strdup(s.next);
		else
			kk = NULL;
		return (kk);
	}
	s.next = ft_grow_line(&s);
	if (!s.next)
		return (NULL);
	while (s.buff && s.buff[s.b] != '\n')
	{
		s.next[s.n] = s.buff[s.b];
		s.b++;
		if (s.buff[s.b] == '\0')
		{
			if(!ft_buffer_up(fd, &s))
				return (NULL);
			if (!s.bytes)
			{
				ft_end(&s);
				if (s.next)
					kk = strdup(s.next);
				else
					kk = NULL;
				return (kk);
			}
			if (!(s.next = ft_grow_line(&s)))
				return (NULL);
			s.n--;
		}
		s.n++;
	}
	s.next[s.n] = s.buff[s.b];
	s.b++;
	kk = strdup(s.next);
	return (kk);
}

int	main(void)
{
	int		fd;
	char	*newln;

	fd = open("read.txt", O_RDONLY);
	while ((newln = get_next_line(fd)) != NULL)
	{
		printf("%s", newln);
		
	}
	free(newln);
	close(fd);
	return (0);
}
