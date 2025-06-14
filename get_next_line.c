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

static t_buffer	b;

char *ft_make_buffers(char *newln, size_t i, int fd)
{
    int bytes;
	if (b.buff == NULL)
		b.buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (b.buff[b.i] == '\0')
	{
		b.buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        bytes = read(fd, b.buff, BUFFER_SIZE);
		if (bytes < 1)
		{	
			if (newln)
				return (newln);
			free(newln);
			return (0);
		}
		b.i = 0;
		newln = ft_grow_line(newln, i, &b.buff[b.i]);
		if (!newln)
		{
			free(newln);
			return (NULL);
		}
	}
	else if (i == 0)
	{
		newln = ft_grow_line(newln, i, &b.buff[b.i]);
		if (!newln)
		{
			free(newln);
			return (NULL);
		}
	}
    return (newln);
}

char	*get_next_line(int fd)
{
	char			*newln;
	size_t				i;

	if (BUFFER_SIZE <= 0 || fd < 0)
    	return (NULL);
	i = 0;
	newln = ft_calloc(1, sizeof(char));
    newln = ft_make_buffers(newln, i, fd);
    if (!newln)
        return (NULL);

    //^^ end
	while (b.buff[b.i] != '\n')
	{
		newln[i] = b.buff[b.i];
		b.i++;
		
        //vv start
        newln = ft_make_buffers(newln, i, fd);
        if (!newln)
            return (NULL);
        //^^ end
		i++;
	}
	newln[i] = b.buff[b.i];
	b.i++;
	return (newln);
}

