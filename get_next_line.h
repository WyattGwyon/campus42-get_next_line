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
	char	buff;
	size_t	i;
}	t_buffer;

typedef struct s_line
{
    char    newln;
    int     i;
}   t_line;

char	*get_next_line(int fd);
int		ft_lengto(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_grow_line(char *newln, size_t i, char *buff);
void	*ft_memset(void *s, int c, size_t n);

#endif
