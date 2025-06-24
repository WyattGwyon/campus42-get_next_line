/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:17:13 by clouden           #+#    #+#             */
/*   Updated: 2025/06/11 23:40:28 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_buffer
{
	char	*buff;
	char	*next;
	size_t	b;
	ssize_t	bytes;
	size_t	n;
	size_t	len;
	int		eof;
}	t_buffer;

char	*get_next_line(int fd);
int		ft_lengto(char *str);
char	*ft_grow_line(t_buffer *s, char * next);
void	*ft_memset(void *s, int c, size_t n);
int		ft_buffer_up(int fd, t_buffer *s);
char	*ft_end(t_buffer *s);
char	*ft_nullout(t_buffer *s, char **next);

#endif
