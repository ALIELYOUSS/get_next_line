/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 05:27:06 by alel-you          #+#    #+#             */
/*   Updated: 2024/11/25 05:54:27 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line(fd)
{
	char		*line;
	static char	*buff;
	int		byte_readed;

	buff = malloc(BUFFER_SIZE + 1);
	line  = NULL;
	byte_readed = 1;
	while (byte_readed > 0)
	{
		byte_readed = read(fd, buff, BUFFER_SIZE);
		if (byte_readed == 0 || byte_readed == -1)
			return (NULL);
		line = malloc(ft_strlen(buff) + 1);
		if (!line)
			return (NULL);
		line = ft_strjoin()
	}	
}

int main()
{
	char *line;
	int fd = open("get-nex_line.h", O_RDONLY, 777);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
}