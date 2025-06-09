/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: clouden <clouden@student.42madrid.com	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/09 13:56:37 by clouden		   #+#	#+#			 */
/*   Updated: 2025/06/09 15:07:47 by clouden          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lengto(char *str)
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

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

char	*ft_grow_line(char *newln, char *buff)
{
	char	*newmem;
	size_t	len;
	int		i;

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
