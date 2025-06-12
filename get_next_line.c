/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:21:36 by clouden           #+#    #+#             */
/*   Updated: 2025/06/12 11:54:50 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buffer	b;

char *ft_make_buffers(char *newln, int i, int fd)
{
    int bytes;
    if (b.buff[b.i] == '\0')
	{
		ft_memset(b.buff, 0, BUFFER_SIZE);
        bytes = read(fd, b.buff, BUFFER_SIZE);
		if (bytes < 1)
		{
			free(newln);
			return (0);
		}
		b.i = 0;
		newln = ft_grow_line(newln, &b.buff[b.i]);
		if (!newln)
		{
			free(newln);
			return (NULL);
		}
	}
	else if (i == 0)
	{
		newln = ft_grow_line(newln, &b.buff[b.i]);
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
	int				i;

	if (BUFFER_SIZE <= 0 || fd < 0)
    	return (NULL);
	i = 0;
	newln = ft_calloc(0, sizeof(char));
	//vv start
    newln = ft_make_buffers(newln, i, fd);
    if (!newln)
        return (NULL);

    //^^ end
	while (b.buff[b.i] != '\n')
	{
		newln[i] = b.buff[b.i];
		b.i++;
		i++;
        //vv start
        newln = ft_make_buffers(newln, i, fd);
        if (!newln)
            return (NULL);
        //^^ end
	}
	newln[i] = b.buff[b.i];
	b.i++;
	return (newln);
}

int	main(void)
{
	int		fd;
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

