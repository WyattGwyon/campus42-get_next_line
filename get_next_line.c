/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: clouden <clouden@student.42madrid.com	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/29 13:01:42 by clouden		   #+#	#+#			 */
/*   Updated: 2025/06/09 15:15:36 by clouden          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	b;
	char			*newln;
	int				i;
	size_t			bytes;

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
/*
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
*/
