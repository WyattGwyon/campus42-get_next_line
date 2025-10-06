/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_re.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:42:13 by clouden           #+#    #+#             */
/*   Updated: 2025/10/06 20:13:53 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_re.h"

size_t	ft_find_newline(char *str)
{
	size_t i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

int	check_stash(char **stash, char **line)
{
	int	len;
	
	if (stash[0])
	{
		len = ft_find_newline(stash);
		if (!len)
			len = ft_strlen(stash);
			
		else 

		return (1);
	}	
	else
		return (o);
}

char *get_next_line(int fd)
{
	char		*buffer[BUFFER_SIZE + 1];
	static char *stash;
	char		*next;
	ssize_t		bytes;

	if (stash[0])
	{
		ft_strlen(stash);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1);
		break;
	while (!ft_find_newline(buffer))
	{
		
	}
	
}
