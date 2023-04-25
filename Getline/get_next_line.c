/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:59:06 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/25 15:22:45 by cbouwen          ###   ########.fr       */
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
	while (!ft_strchr(static_line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		static_line = ft_strjoin(buffer, static_line);
	}
	free(buffer);
	return (static_line);
}

char	*ft_new_static(char *static_line)
{
	char	*new_static;
	size_t	i;
	size_t	j;

	i = 0;
	while (static_line[i] != '\n' && static_line[i])
		i++;
	if (static_line[i] == '\0')
	{
		new_static = (char *)malloc(sizeof(char) * 1);
		if (!new_static)
			return (NULL);
		new_static[0] = '\0';
		free(static_line);
		return (new_static);
	}
	i++;
	new_static = (char *)malloc(sizeof(char) * (ft_strlen(static_line) - i
				+ 1));
	if (!new_static)
		return (NULL);
	j = 0;
	while (static_line[i])
		new_static[j++] = static_line[i++];
	new_static[j] = '\0';
	free(static_line);
	return (new_static);
}

char	*ft_find_line(char *static_line)
{
	size_t	i;
	size_t	j;
	char	*next_line;

	i = 0;
	if (!static_line[i])
		return (NULL);
	while (static_line[i] != '\n' && static_line[i])
		i++;
	if (static_line[i] == '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * i + 1);
	if (!next_line)
		return (NULL);
	j = 0;
	while (j != i)
	{
		next_line[j] = static_line[j];
		j++;
	}
	next_line[j] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*static_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_line = ft_readline(fd, static_line);
	if (!static_line)
		return (NULL);
	next_line = ft_find_line(static_line);
	static_line = ft_new_static(static_line);
	//free(static_line);
	return (next_line);
}

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
