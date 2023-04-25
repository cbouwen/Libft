/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:41:26 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/25 15:03:08 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//int     main(int argc, char **argv);
char	*get_next_line(int fd);
char	*ft_readline(int fd, char *static_line);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *buffer, char *static_line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_new_static(char *static_line);
char	*ft_find_line(char *static_line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#endif
