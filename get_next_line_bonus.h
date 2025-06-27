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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_buffer
{
	char	*buff[FD_MAX];
	int		b[FD_MAX];
	ssize_t	bytes;
	size_t	len;
}	t_buffer;

char	*get_next_line(int fd);
int		ft_lengto(char *str);
char	*ft_grow_line(t_buffer *s, char *next, int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_buffer_up(int fd, t_buffer *s);
char	*ft_nullout(t_buffer *s, char **next, int fd);
int		ft_status(int fd, t_buffer *s, char **next);

#endif
