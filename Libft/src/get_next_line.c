/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:25:40 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/06 01:56:46 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* get_next_line.c: Reads a line from a file descriptor fd and stores it in the
string line. If there is no more line to read or an error occurs,
it returns an appropriate status code. */

#include "../includes/libft.h"

int	ft_count_len_line(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	while (*str && *str != '\n')
	{
		count++;
		str++;
	}
	return (count);
}

char	*read_fd(int fd, char *line)
{	
	int		bytes;
	char	*buffer;

	bytes = 1;
	if (!line)
		line = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin_and_free(line, buffer);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || *buffer == '\0')
		return (NULL);
	line = ft_calloc(ft_count_len_line(buffer) + 2, 1);
	if (!line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_remaining_char_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = ft_count_len_line(buffer);
	j = 0;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd, char *buffer)
{
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_remaining_char_buffer(buffer);
	free(buffer);
	return (line);
}
