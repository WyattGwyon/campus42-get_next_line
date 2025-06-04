/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:17:13 by clouden           #+#    #+#             */
/*   Updated: 2025/06/04 20:13:46 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stddef.h>

typedef struct s_buffer{
	char	*buffer;
	size_t 	pos;
} t_buffer;

char	*get_next_line(int fd);

# endif
