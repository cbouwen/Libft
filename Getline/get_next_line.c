/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:59:06 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/24 17:19:59 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *static_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(static_line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);	
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		static_line = ft_strjoin(buffer,static_line);//utils, does this work on empty string?
		if (bytes_read < BUFFER_SIZE)
			break;
	}
	free(buffer);
	return (static_line);
}

/*char	*ft_find_line(char *static_line)
{

	return (next_line);
}

char	*ft_new_static(char *static_line)
{

	return (static_line);
}*/

char	*get_next_line(int fd)
{
	static char	*static_line;
	/*char	*next_line;*/ //disabled for test

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_line = ft_readline(fd, static_line);//reads line except when we find a '\n'. we just keep the static line in this case
	if (!static_line)
		return (NULL);
	/*next_line = ft_find_line(static_line);//gets the next line out of our static line up until '\n'
	static_line = ft_new_static(static_line);//changes our static line to static line - the next line we just got*/
	return (static_line);//!!!!! change into next_line. this was pure for testing purposes
}
//we good when there are no '\n'?

/*int	main(int argc, char **argv)
{
	int	fd;
	char	*next_line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
		close (fd);
	}
}*/
