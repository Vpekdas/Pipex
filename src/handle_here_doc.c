/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:09 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/06 02:00:43 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_free_gnl(char *line, char *buffer)
{
	free(line);
	free(buffer);
}

static char	*ft_gnl(char **line, int fd, char *buffer)
{
	*line = get_next_line(fd, buffer);
	return (*line);
}

void	ft_exec_here_doc(char **av, char **envp, char *out_path, t_here *here)
{
	char	*temp;
	int		pipe;
	char	*buffer;

	buffer = NULL;
	write(1, "> ", 2);
	while (ft_gnl(&temp, 0, buffer))
	{
		if (ft_strncmp(temp, here->limiter, ft_strlen(temp) - 1) == 0
			&& temp[0] != '\n')
		{
			ft_free_gnl(temp, buffer);
			break ;
		}
		write(1, "> ", 2);
		write (here->fd, temp, ft_strlen(temp));
		ft_free_gnl(temp, buffer);
	}
	close(here->fd);
	here->fd = open("here_doc", O_RDONLY);
	pipe = ft_exec_first_cmd(av[3], envp, here->fd);
	pipe = ft_exec_last_cmd(av[4], envp, pipe, out_path);
	close(here->fd);
	if (unlink("here_doc") == ERROR)
		ft_perror_msg();
}
