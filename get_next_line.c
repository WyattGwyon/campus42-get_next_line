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

// char	*ft_phase_ctrl(int fd, t_buffer *s, char *next, int n)
// {
// 	if (!ft_buffer_up(fd, &s) || s->bytes < 1 || s->eof == 1)
// 	{
// 		if (s->bytes == 0 && s->eof != 1)
// 		{
// 			s->eof = 1;
// 			return (next);
// 		}
// 		return (ft_nullout(&s, &next));
// 	}
// 	next = ft_grow_line(&s, next, n);
// 	if (!next)
// 		return (ft_nullout(&s, &next));
// }

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

char	*get_next_line(int fd)
{
	static t_buffer	s;
	char			*next;
	int				n;

	next = NULL;
	n = 0;
	if (!ft_buffer_up(fd, &s) || s.bytes < 1)
	{
		if (s.bytes == 0 && s.eof != 1)
		{
			s.eof = 1;
			if (s.buff)
			{
				free(s.buff);
				s.buff = NULL;
			}
			return (next);
		}
		return (ft_nullout(&s, &next));
	}
	next = ft_grow_line(&s, next);
	if (!next)
		return (ft_nullout(&s, &next));
	while (s.buff && s.buff[s.b] != '\n')
	{
		next[n] = s.buff[s.b];
		s.b++;
		if (s.buff[s.b] == '\0')
		{
			if (!ft_buffer_up(fd, &s) || s.bytes < 1)
			{
				if (s.bytes == 0 && s.eof != 1)
				{
					s.eof = 1;
					return (next);
				}
				return (ft_nullout(&s, &next));
			}
			next = ft_grow_line(&s, next);
			if (!next)
				return (ft_nullout(&s, &next));
		}
		n++;
	}
	next[n] = s.buff[s.b];
	s.b++;
	return (next);
}
// void gnl(int fd, char const * expectedReturn)
// {
// 	char *  gnlReturn = get_next_line(fd);
// 	if (expectedReturn == NULL && gnlReturn == NULL)
// 		printf("OK -> both are NULL");
// 	if (!strcmp(gnlReturn, expectedReturn))
// 	{
// 		printf("Got: 		%s\n", gnlReturn);
// 		printf("Expected:	%s\n", expectedReturn);
// 	}
// 	else
// 		printf("OK");
// 	free(gnlReturn);
// }
// int main(void)
// {
// 	char *name = "read_error.txt";
// 	int fd = open(name, O_RDONLY);
// 	/* 1 */ gnl(fd, "aaaaaaaaaa\n");
// 	/* 2 */ gnl(fd, "bbbbbbbbbb\n");
// 	// set the next read call to return -1
// 	int next_read_error = 1;
// 	if (BUFFER_SIZE > 100) {
// 		char *temp;
// 		do {
// 			temp = get_next_line(fd);
// 			free(temp);
// 		} while (temp != NULL);
// 	}
// 	/* 3 */ gnl(fd, NULL);
// 	next_read_error = 0;
// 	close(fd);
// 	fd = open(name, O_RDONLY);
// 	/* 4 */ gnl(fd, "aaaaaaaaaa\n");
// 	/* 5 */ gnl(fd, "bbbbbbbbbb\n");
// 	/* 6 */ gnl(fd, "cccccccccc\n");
// 	/* 7 */ gnl(fd, "dddddddddd\n");
// 	/* 8 */ gnl(fd, NULL);
// 	return (0);
// }


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
