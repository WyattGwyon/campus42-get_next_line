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

#include "get_next_line_bonus.h"

char	*ft_nullout(t_buffer *s, char **next, int fd)
{
	if (s->buff[fd])
	{
		free(s->buff[fd]);
		s->buff[fd] = NULL;
	}
	if (next && *next)
	{
		free(*next);
		*next = NULL;
	}
	return (NULL);
}

int	ft_status(int fd, t_buffer *s, char **next)
{
	if (!ft_buffer_up(fd, s) || s->bytes < 1)
	{
		if (s->bytes == 0)
		{
			free(s->buff[fd]);
			s->buff[fd] = NULL;
			return (1);
		}
		ft_nullout(s, next, fd);
		return (-1);
	}
	*next = ft_grow_line(s, *next, fd);
	if (!*next)
	{
		ft_nullout(s, next, fd);
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer	s;
	char			*next;
	int				n;
	int				status;

	next = NULL;
	n = 0;
	status = ft_status(fd, &s, &next);
	if (status != 0)
		return (next);
	while (s.buff[fd] && s.buff[fd][s.b[fd]] && s.buff[fd][s.b[fd]] != '\n')
	{
		next[n] = s.buff[fd][s.b[fd]];
		s.b[fd]++;
		if (s.buff[fd][s.b[fd]] == '\0')
		{
			status = ft_status(fd, &s, &next);
			if (status != 0)
				return (next);
		}
		n++;
	}
	if (s.buff[fd][s.b[fd]] == '\n')
		next[n] = s.buff[fd][s.b[fd]];
	return (++s.b[fd], next);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*newln;
// 	fd = open("read.txt", O_RDONLY);
// 	while ((newln = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", newln);	
// 		free(newln);
// 	}
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*newln, *newln2;
// 	int fd = open("name", O_RDONLY);
// 	int fd2 = open("other", O_RDONLY);
// 	t_buffer s;
// 	//s.re = 0;

// 	newln = get_next_line(fd);
// 	printf("aaaaaaaaaa\n%s\n", newln);

// 	newln2 = get_next_line(fd2);
// 	printf("0123456789\n%s\n", newln2);

// 	newln = get_next_line(fd);
// 	printf("bbbbbbbbbb\n%s\n", newln);

// 	newln2 = get_next_line(fd2);
// 	printf("012345678\n%s\n", newln2);
// 	//s.re = 1;
// 	if (BUFFER_SIZE > 100) {
// 		char *temp;
// 		do
// 		{
// 			temp = get_next_line(fd);
// 			free(temp);
// 		} while (temp != NULL);
// 	}
// 	newln = get_next_line(fd);
// 	printf("ERRORNULL >%s<\n", newln);
// 	//s.re = 0;
// 	close(fd);

// 	newln2 = get_next_line(fd2);
// 	printf("90123456789\n%s\n", newln2);

// 	fd = open("name", O_RDONLY);
// 	newln = get_next_line(fd);
// 	printf("aaaaaaaaaa\n%s\n", newln);

// 	newln2 = get_next_line(fd2);
// 	printf("0123456789\n%s\n", newln2);

// 	newln = get_next_line(fd);
// 	printf("bbbbbbbbbb\n%s\n", newln);

// 	newln = get_next_line(fd);
// 	printf("cccccccccc\n%s\n", newln);

// 	newln2 = get_next_line(fd2);
// 	printf("xxxx\n%s\n", newln2);

// 	newln2 = get_next_line(fd2);
// 	printf("NULL >%s<\n", newln2);

// 	newln = get_next_line(fd);
// 	printf("dddddddddd\n%s\n", newln);

// 	newln = get_next_line(fd);
// 	printf("NULL >%s<\n", newln);
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }

// int main(void)
// {
// 	char	*newln;
// 	int fd_1 = open("other", O_RDONLY);
// 	int fd_2 = open("other", O_RDONLY);

// 	/* 1 */ newln = get_next_line(fd_1); 
// 	printf("1GOT:%s1EXP:0123456789\n\n", newln);

// 	/* 2 */ newln = get_next_line(fd_2); 
// 	printf("2GOT:%s2EXP:0123456789\n\n", newln);

// 	/* 3 */ newln = get_next_line(fd_1); 
// 	printf("3GOT:%s3EXP:012345678\n\n", newln);

// 	/* 4 */ newln = get_next_line(fd_2); 
// 	printf("4GOT:%s4EXP:012345678\n\n", newln);

// 	/* 5 */ newln = get_next_line(fd_2); 
// 	printf("5GOT:%s5EXP:90123456789\n\n", newln);

// 	/* 6 */ newln = get_next_line(fd_2); 
// 	printf("6GOT:%s6EXP:0123456789\n\n", newln);

// 	/* 7 */ newln = get_next_line(fd_2); 
// 	printf("7GOT:%s7EXP:xxxx\n\n", newln);

// 	/* 8 */ newln = get_next_line(fd_2); 
// 	printf("8GOT:%s8EXP:NULL\n\n", newln);

// 	/* 9 */ newln = get_next_line(fd_1); 
// 	printf("9GOT:%s9EXP:90123456789\n\n", newln);

// 	/* 10 */newln = get_next_line(fd_1); 
// 	printf("10GOT:%s10EXP:0123456789\n\n", newln);

// 	/* 11 */newln = get_next_line(fd_1);

// 	printf("11GOT:%s11EXP:xxxx\n\n", newln);
// 	/* 12 */newln = get_next_line(fd_1);

// 	printf("12GOT:%s12EXP:NULL", newln);

// 	return (0);
// }

// void populate_expected(char *buffer, int n)
// {
// 	int i = 0;
// 	while (i < n)
// 	{
// 		i += sprintf(buffer + i, "0123456789");
// 	}
// 	buffer[n] = 0;
// }

// int main(void)
// {

// 		char expected[20000 + 2];
// 		populate_expected(expected, 20000);
// 		expected[20000] = '\n';
// 		expected[20001] = 0;

// 		char *newln;
// 		int fd_1 = open("other", O_RDONLY);
// 		int fd_2 = open("other", O_RDONLY);
// 		int fd_3 = open("other", O_RDONLY);
// 		/* 1 */ newln = get_next_line(fd_1);  
// 			printf("1GOT:       %sEXP:          0123456789\n\n", newln);

// 		/* 2 */ newln = get_next_line(fd_2);  
// 			printf("2GOT:       %sEXP:          0123456789\n\n", newln);

// 		/* 3 */ newln = get_next_line(fd_3);  
// 			printf("3GOT:       %sEXP:          0123456789\n\n", newln);

// 		/* 4 */ newln = get_next_line(fd_1);  
// 			printf("4GOT:       %sEXP:          012345678\n\n", newln);

// 		/* 5 */ newln = get_next_line(fd_2);  
// 			printf("5GOT:       %sEXP:          012345678\n\n", newln);

// 		/* 6 */ newln = get_next_line(fd_2); 
// 			printf("6GOT:       %sEXP:          90123456789\n", newln);

// 		int fd_4 = open("giant.txt", O_RDONLY);
// 		/* 7 */ newln = get_next_line(fd_2);  
// 			printf("7GOT:       %sEXP:          0123456789\n\n", newln);

// 		/* 8 */ newln = get_next_line(fd_3);  
// 			printf("8GOT:       %sEXP:          012345678\n\n", newln);

// 		/* 9 */ newln = get_next_line(fd_4);  
// 			printf("9GOT:       %sEXP:           %s", newln, expected);

// 		/* 10 */ newln = get_next_line(fd_2);  
// 			printf("10GOT:       %sEXP:          xxxx\n\n", newln);

// 		/* 11 */ newln = get_next_line(fd_2);  
// 			printf("11GOT:       %sEXP:          NULL\n\n", newln);

// 		/* 12 */ newln = get_next_line(fd_1);  
// 			printf("12GOT:       %sEXP:          90123456789\n\n", newln);

// 		/* 13 */ newln = get_next_line(fd_4);  
// 			printf("13GOT:       %sEXP:          another line!!!\n\n", newln);

// 		/* 14 */ newln = get_next_line(fd_1);  
// 			printf("14GOT:       %sEXP:          0123456789\n\n", newln);

// 		/* 15 */ newln = get_next_line(fd_4);  
// 			printf("15GOT:       %sEXP:          NULL\n\n", newln);

// 		/* 16 */ newln = get_next_line(fd_1);  
// 			printf("16GOT:       %sEXP:          xxxx\n\n", newln);

// 		/* 17 */ newln = get_next_line(fd_4);  
// 			printf("17GOT:       %sEXP:          NULL\n\n", newln);

// 		/* 18 */ newln = get_next_line(fd_3);  
// 			printf("18GOT:       %sEXP:          90123456789\n\n", newln);

// 		/* 19 */ newln = get_next_line(fd_3);  
// 			printf("19GOT:       %sEXP:          0123456789\n\n", newln);

// 		/* 20 */ newln = get_next_line(fd_1);  
// 			printf("20GOT:       %sEXP:          NULL\n\n", newln);

// 		/* 21 */ newln = get_next_line(fd_3);  
// 			printf("21GOT:       %sEXP:          xxxx\n\n", newln);

// 		/* 22 */ newln = get_next_line(fd_3);  
// 			printf("22GOT:       %sEXP:          NULL\n", newln);

// }