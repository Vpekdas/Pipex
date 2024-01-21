/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:17:54 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/21 18:05:51 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = NULL;
	cmd = ft_split(av, ' ');
	path = ft_create_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
		return (ft_check_execve());
	return (0);
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
			exit(1);
	}
	close(fd[1]);
	close(infile);
	return (fd[0]);
}

int	ft_exec_last_cmd(char *av, char **envp, int pipe_in, char *out_path)
{
	int	pid;
	int	outfile;
	int result;

	outfile = 1;
	pid = fork();
	if (pid == -1)
		return (ft_check_fork());
	if (pid == 0)
	{
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
		outfile = open(out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		result = ft_exec_cmd(av, envp);
		if (result == -1)
			return (ft_check_execve());
	}
	close(pipe_in);
	close(outfile);
	return (0);
}

int	ft_exec_middle_cmd(char *av, char **envp, int pipe_in)
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
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		result = ft_exec_cmd(av, envp);
		if (result == -1)
			return (ft_check_execve());
	}
	close(pipe_in);
	close(fd[1]);
	return (fd[0]);
}
