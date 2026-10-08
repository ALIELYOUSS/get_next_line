/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:38:13 by alel-you          #+#    #+#             */
/*   Updated: 2024/12/03 18:01:48 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 13
# endif

char	*ft_getline(char *rest);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, char c);
char	*ft_get_rest(char *str);

#endif
