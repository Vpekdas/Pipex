/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:09 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/03 16:55:21 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_gnl(char *line, char *buffer)
{
	free(line);
	free(buffer);
}

char	*ft_gnl(char **line, int fd, char *buffer)
{
	*line = get_next_line(fd, buffer);
	return (*line);
}

void	ft_exec_here_doc(char **av, char **envp, char *out_path)
{
	char	*limiter;
	int		here_doc;
	char	*temp;
	int		pipe;
	char	*buffer;

	limiter = av[2];
	here_doc = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	buffer = NULL;
	while (ft_gnl(&temp, 0, buffer))
	{
		if (ft_strncmp(temp, limiter, ft_strlen(temp) - 1) == 0
			&& temp[0] != '\n')
		{
			ft_free_gnl(temp, buffer);
			break ;
		}
		write (here_doc, temp, ft_strlen(temp));
		ft_free_gnl(temp, buffer);
	}
	close(here_doc);
	here_doc = open("here_doc", O_RDONLY);
	pipe = ft_exec_first_cmd(av[3], envp, here_doc);
	pipe = ft_exec_last_cmd(av[4], envp, pipe, out_path);
	close(here_doc);
}
