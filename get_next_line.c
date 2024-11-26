/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 05:00:19 by alel-you          #+#    #+#             */
/*   Updated: 2024/11/26 02:42:51 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	byte_readed;
	static char	*buff;
	char	*tmp_buff;
	char 	*line;
	
	tmp_buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	byte_readed = 1;
	line = NULL;
	if (buff)
		line = strdup(buff);
	while (byte_readed > 0)
	{
		byte_readed = read(fd, tmp_buff, BUFFER_SIZE);
		if (byte_readed < 0)
		{
			free(tmp_buff);
			return (NULL);
		}
		tmp_buff[byte_readed] = '\0';

		line = ft_strjoin(line, get_line(tmp_buff));
		
		if (line && strchr(line, '\n'))
		{
   	 		puts(line);
   	 		puts(tmp_buff);
			buff = find_next_line(tmp_buff);
			return (line);
		}
	}
	// if (buff && tmp_buff[ft_strlen(tmp_buff)] == '\n')
	// {
	// 	buff = find_next_line(tmp_buff);
	// 	tmp_buff = buff;
	// }
	return (line);
}

int main()
{
	char *line;
	int fd = open("yest.txt", O_RDONLY , 777);
	if (strcmp("exit", line) == 0)
		return (0);
	line = get_next_line(fd);

	printf("line => %s\n", line);
	printf("line => %s\n", get_next_line(fd));
	return 0;
}