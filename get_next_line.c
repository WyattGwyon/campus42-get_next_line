/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:01:42 by clouden           #+#    #+#             */
/*   Updated: 2025/06/06 23:30:47 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int ft_lengto(char *str)
{
	int	len;
    
    if (!str)
        return (0);
	len = 0;
	while (*str != '\n' && *str != '\0')
	{
		len++;
		str++;
	}
	if (*str == '\n')
		return (++len);
	return (len);
}

void    *ft_calloc(size_t count, size_t size)
{
    void    *mem;
    size_t  i;

    i = 0;
    if (count == 0 || size == 0)
            return (malloc(0));
    mem = malloc(count * size);
    if (!mem)
            return (NULL);
    while (i < (count * size))
   {
            ((unsigned char *)mem)[i] = 0;
            i++;
    }
    return (mem);
}

char *ft_grow_line(char *newln, char *buff)
{
    char    *newmem;
    size_t  len;
    int     i;
    
    len = ft_lengto(newln) + ft_lengto(buff);
    newmem = ft_calloc(len + 1, sizeof(char));
    if (newmem == NULL)
        return (NULL);
    if (newln)
    {
        i = 0;
        while (newln[i])
        {
            newmem[i] = newln[i];
            i++;
        }
        free(newln);
    }
    return (newmem);
}

char *initiate_buffer(char *buffer, int fd)
{
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));	
    if (!buffer)
        return (NULL);
   // bytes = read(fd, buffer, BUFFER_SIZE);
   // if (!bytes);
   //     return (0);
    return (buffer);     
}

char *get_next_line(int fd)
{
	static  t_buffer b;
	char 	*newln;
	int		i;
    size_t  bytes;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);
    i = 0;
    newln = NULL;
	if (!b.buff[b.i])
    {
        bytes = read(fd, b.buff, BUFFER_SIZE);
        if (!bytes)
            return (0);
        b.i = 0;
    }
    newln = ft_grow_line(newln, &b.buff[b.i]);
    if (!newln)
        return (NULL);
	while (b.buff[b.i] != '\n')
	{
		newln[i] = b.buff[b.i];
        b.i++;
        i++;
        if (!b.buff[b.i])
        {
            bytes = read(fd, b.buff, BUFFER_SIZE);
            if (!bytes)
                return (0);
            b.i = 0;
            newln = ft_grow_line(newln, b.buff);
            if (!newln)
                return (NULL);
        }
	}
    newln[i] = b.buff[b.i];
    b.i++;
    return (newln);
}

int main(void)
{
    int     fd;
	char	*newln;
    
    fd = open("titus.txt", O_RDONLY);
    
    newln = get_next_line(fd);
    printf("%s", newln);

    while (newln)
    {
        newln = get_next_line(fd);
        printf("%s", newln);
    }
    free(newln);
    close(fd);
    return (0);
}
