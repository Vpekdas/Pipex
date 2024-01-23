/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:17:54 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/23 17:06:47 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = NULL;
	cmd = ft_split(av, ' ');
	if (!cmd)
		return (ft_perror_msg("SPLIT ERROR"));
	path = ft_create_path(cmd[0], envp);
	if (!path)
	{
		ft_free_split(cmd);
		return (ft_perror_msg("PATH ERROR"));
	}
	if (execve(path, cmd, envp) == ERROR)
	{
		ft_free_split(cmd);
		free(path);
		return (ft_perror_msg("COMMAND ERROR"));
	}
	ft_free_split(cmd);
	free(path);
	return (0);
}

int	ft_exec_first_cmd(char *av, char **envp, int infile)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == ERROR)
		return (ft_perror_msg("PIPE ERROR IN FIRST CMD"));
	pid = fork();
	if (pid == ERROR)
		return (ft_perror_msg("FORK ERROR IN FIRST CMD"));
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(infile, STDIN_FILENO) == ERROR)
			return (ft_perror_msg("DUP2 ERROR IN FIRST CMD"));
		close(infile);
		if (dup2(fd[1], STDOUT_FILENO) == ERROR)
			return (ft_perror_msg("DUP2 ERROR IN FIRST CMD"));
		close(fd[1]);
		if (ft_exec_cmd(av, envp) == ERROR)
			return (ERROR);
	}
	close(fd[1]);
	close(infile);
	return (fd[0]);
}

int	ft_exec_last_cmd(char *av, char **envp, int pipe_in, char *out_path)
{
	int	pid;
	int	outfile;

	outfile = 42;
	pid = fork();
	if (pid == ERROR)
		return (ft_perror_msg("FORK ERROR IN LAST CMD"));
	if (pid == 0)
	{
		if (dup2(pipe_in, STDIN_FILENO) == ERROR)
			return (ft_perror_msg("DUP2 ERROR IN LAST CMDTEST"));
		close(pipe_in);
		outfile = open(out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == ERROR)
			return (ft_perror_msg("OPEN ERROR FOR OUTFILE"));
		if (dup2(outfile, STDOUT_FILENO) == ERROR)
			return (ft_perror_msg("DUP2 ERROR IN LAST CMD"));
		close(outfile);
		if (ft_exec_cmd(av, envp) == ERROR)
			return (ERROR);
	}
	close(pipe_in);
	close(outfile);
	return (0);
}

int	ft_exec_middle_cmd(char *av, char **envp, int pipe_in)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == ERROR)
		return (ft_perror_msg("PIPE ERROR"));
	pid = fork();
	if (pid == ERROR)
		return (ft_perror_msg("FORK ERROR"));
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(pipe_in, STDIN_FILENO) == ERROR)
			return (ft_perror_msg("DUP2 ERROR"));
		close(pipe_in);
		if (dup2(fd[1], STDOUT_FILENO) == ERROR)
			return (ft_perror_msg("DUP2 ERROR"));
		close(fd[1]);
		if (ft_exec_cmd(av, envp) == ERROR)
			return (ERROR);
	}
	close(pipe_in);
	close(fd[1]);
	return (fd[0]);
}
