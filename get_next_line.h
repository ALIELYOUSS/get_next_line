/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 04:47:25 by alel-you          #+#    #+#             */
/*   Updated: 2024/11/26 01:59:07 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10 
#endif

char    *ft_check_what_after_new_line(char *buff);
char    *get_line(char *buff);
char    *ft_check_line(char *str);
int     ft_strlen(char *str);
char    *find_next_line(char *tmp_buff);
char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
#endif