/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:47:49 by alel-you          #+#    #+#             */
/*   Updated: 2024/12/03 18:00:35 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_getline(char *rest)
{
	char	*line;
	int		i;
	int		count;

	i = 0;
	line = NULL;
	count = 0;
	if (!rest || !rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] && rest[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (count < i)
	{
		line[count] = rest[count];
		count++;
	}
	line[count] = '\0';
	return (line);
}

char	*ft_get_rest(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (ft_strdup(str + i));
}
