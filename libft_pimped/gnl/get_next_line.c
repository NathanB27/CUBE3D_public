/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tle-Prig <tom.leprigent@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:30:22 by Tle-Prig          #+#    #+#             */
/*   Updated: 2024/12/01 12:46:39 by Tle-Prig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	long long	n_read;
	static char	buffer[BUFFER_SIZE + 1];
	char		*rtn;
	long long	rtn_size;

	rtn = NULL;
	rtn_size = 0;
	while (no_line(buffer, &rtn, &rtn_size))
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == 0 && (*rtn))
		{
			buffer[0] = '\0';
			return (rtn);
		}
		if (n_read <= 0)
		{
			buffer[0] = '\0';
			free(rtn);
			return (NULL);
		}
		else
			buffer[n_read] = '\0';
	}
	return (rtn);
}
/*
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	char	*i;
	i = get_next_line(fd);
	printf("%s", i);
	free(i);
	i = get_next_line(fd);
	printf("%s", i);
	free(i);
	i = get_next_line(fd);
	printf("%s", i);
	free(i);
	i = get_next_line(0);
	printf("%s", i);
	free(i);
	i = get_next_line(0);
	printf("%s", i);
	free(i);
	i = get_next_line(-100);
	printf("%s", i);
	free(i);
}*/
