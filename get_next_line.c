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

	if(!ft_buffer_up(fd, &s))
		return (NULL);
	if (!s.bytes)
		return (ft_end(&s));
	if (!(s.next = ft_grow_line(&s)))
		return (NULL);
	while (s.buff && s.buff[s.b] != '\n')
	{
		s.next[s.n] = s.buff[s.b];
		s.b++;
		s.n++;
		if (s.buff[s.b] == '\0')
		{
			if(!ft_buffer_up(fd, &s))
				return (NULL);
			if (!s.bytes)
				return (ft_end(&s));
			if (!(s.next = ft_grow_line(&s)))
				return (NULL);
		}
	}
	s.next[s.n] = s.buff[s.b];
	s.b++;
	return (s.next);
}

int	main(void)
{
	int		fd;
	char	*newln;

	fd = open("files/41_with_nl", O_RDONLY);
	while ((newln = get_next_line(fd)) != NULL)
	{
		printf("%s", newln);
		
	}
	free(newln);
	close(fd);
	return (0);
}
