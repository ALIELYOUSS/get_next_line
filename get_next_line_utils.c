/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 05:02:59 by alel-you          #+#    #+#             */
/*   Updated: 2024/11/26 02:39:20 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str && str[i] && str[i] != '\n')
    {
        i++;
    }
    return (i);
}

char    *find_next_line(char *tmp_buff)
{
    int i;
    int x;
    char *rest;

    if (!tmp_buff)
        return (NULL);
    i = ft_strlen(tmp_buff);
    x = 0;
    rest = NULL;
    while (tmp_buff[i + x])
        x++;
    rest = malloc(sizeof(char) * (x + 1));
    if (!rest)
    {
        free(rest);
        return (NULL);
    }
    x = 0;
    while (tmp_buff[i + x])
    {
        rest[x] = tmp_buff[i + x];
        x++;
    }
    rest[x] = 0;
    return (rest);
}

char    *get_line(char *buff)
{
    int i;
    char    *line;

    i = 0;
    if (!buff)
        return (NULL);
    line = malloc(ft_strlen(buff) + 1 + !(!(strchr(buff, '\n'))));
    if (!line)
    {
        free(line);
        return (NULL);
    }
    while (buff && buff[i] && buff[i] != '\n')
    {
        line[i] = buff[i];
        i++;
    }
    if (buff[i] == '\n')
        line[i++] = '\n';
    line[i] = 0;
    return (line);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *joined;
    int     i;
    int     x;
    
    i = 0;
    x = 0;
    if (!s1 && s2)
        return (strdup(s2));
    if (!s2)
        return (NULL);
    joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!joined)
        return (NULL);
    while (s1 && s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    while (s2 && s2[x])
    {
        joined[i + x] = s2[x];
        x++;
    }
    joined[i + x] = '\0';
    return (joined);
}