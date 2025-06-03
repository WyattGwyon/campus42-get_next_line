/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:01:42 by clouden           #+#    #+#             */
/*   Updated: 2025/06/03 20:49:42 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int ft_lengto(char *str)
{
	int	len;

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

char *get_next_line(int fd)
{
	static char	*buff;
	int			len;
	char 		*newln;
	int			i;
	
	i = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);	
    if (buff == NULL)
        return (NULL);
	read(fd, buff, BUFFER_SIZE);
	len = ft_lengto(buff);
	newln = malloc(len + 1);
	while (*buff != '\0')
	{
		newln[i] = *buff;
		if (newln[i] != '\n')
		{
			i = 0;
			buff++;
			return (newln);
		}
		i++;
	}
	if (*buff == '\0')
	{
		remeasure your newln
		fill new memory allocation with current new line
		continue filling new line with buffer
	}
}

int main(void)
{
    int     fd;
	char	*newln;
    
    fd = open("titus.txt", O_RDONLY);
    newln = get_next_line(fd);
    
    bytes = read(fd, buffer, size - 1);
    printf("%zu\n",bytes);
    printf("%s", buffer);
    free(buffer);

    close(fd);
    return (0);
}
