/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:17:13 by clouden           #+#    #+#             */
/*   Updated: 2025/06/06 19:01:01 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stddef.h>

typedef struct s_buffer{
	char	buff[BUFFER_SIZE + 1];
	size_t 	i;
} t_buffer;

char	*get_next_line(int fd);

# endif
