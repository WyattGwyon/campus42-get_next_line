/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:01:42 by clouden           #+#    #+#             */
/*   Updated: 2025/05/29 20:46:12 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	static char *buf;
	size_t = s;

	buf = malloc(BUFFER_SIZE);
	s = read(fd, buf, BUFFER_SIZE) 
}
