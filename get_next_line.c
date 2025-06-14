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

	if(!start_up(fd, &s))
		return (NULL);
	//return (s.line);
	
	while((s.bytes = read(fd, s.buff, BUFFER_SIZE)))
		return (s.buff);
	s.line = create_line(&s);
	free(s.buff);
	s.buff = NULL;
	return (NULL);
	//s.buff = start_up(fd, s);	
}

int	main(void)
{
	int		fd;
	char	*newln;

	fd = open("shortitus.txt", O_RDONLY);
	while ((newln = get_next_line(fd)) != NULL)
	{
		printf("%s", newln);
		free(newln);
	}
	close(fd);
	return (0);
}
