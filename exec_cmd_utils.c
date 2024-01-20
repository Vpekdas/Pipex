/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:17:54 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/20 17:53:32 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

int	ft_exec_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = NULL;
	cmd = ft_split(av, ' ');
	path = ft_create_path(cmd[0], envp);
	return (execve(path, cmd, envp));
}

int	ft_exec_first_cmd(char *av, char **envp, int infile)
{
	int	fd[2];
	int	pid;
	int	result;

	if (pipe(fd) == -1)
		return (ft_check_pipe());
	pid = fork();
	if (pid == -1)
		return (ft_check_fork());
	if (pid == 0)
	{
		close(fd[0]);
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		result = ft_exec_cmd(av, envp);
		if (result == -1)
			return (ft_check_execve());
	}
	else
		close(fd[1]);
	return (fd[0]);
}

int	ft_exec_last_cmd(char *av, char **envp, int pipe_in, int outfile)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (ft_check_fork());
	if (pid == 0)
	{
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		ft_exec_cmd(av, envp);
		exit(0);
	}
	else
		close(pipe_in);
	return (0);
}

int	ft_exec_middle_cmd(char *av, char **envp, int pipe_in)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (ft_check_pipe());
	pid = fork();
	if (pid == -1)
		return (ft_check_fork());
	if (pid == 0)
	{
		close(fd[0]);
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_exec_cmd(av, envp);
	}
	else
	{
		close(fd[1]);
		close(pipe_in);
	}
	return (fd[0]);
}