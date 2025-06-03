/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:01:42 by clouden           #+#    #+#             */
/*   Updated: 2025/06/02 12:08:29 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
/*
char *get_next_line(int fd)
{
	static char *buf;
	size_t = s;

	buf = malloc(BUFFER_SIZE);
    if (buf == NULL)
        return (NULL);
	s = read(fd, buf, BUFFER_SIZE);

}
*/
int main(void)
{
    int     fd;
    char    *buffer;
    int     size;
    size_t  bytes;
    
    fd = open("titus.txt", O_RDONLY);
    size = 10;
    buffer = malloc(size);
    buffer[size] = 0;
    bytes = read(fd, buffer, size - 1);
    printf("%zu\n",bytes);
    printf("%s\n", buffer);
    
    bytes = read(fd, buffer, size - 1);
    printf("%zu\n",bytes);
    printf("%s", buffer);
    free(buffer);

    close(fd);
    return (0);
}
