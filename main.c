/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/19 16:23:36 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_execute_commands(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = NULL;
	cmd = ft_split(av, ' ');
	path = ft_create_path(cmd[0], envp);
	execve(path, cmd, envp);
}


int	ft_execute_first_command(char *av, char **envp, int infile)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute_commands(av, envp);
	}
	else
		close(fd[1]);
	return (fd[0]);
}

void	ft_execute_last_command(char *av, char **envp, int pipe_in, int outfile)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		ft_execute_commands(av, envp);
	}
	else
		close(pipe_in);
}

int		ft_execute_middle_command(char *av, char **envp, int pipe_in)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute_commands(av, envp);
	}
	else
	{
		close(fd[1]);
		close(pipe_in);
	}
	return (fd[0]);
}

int main(int ac, char **av, char **envp)
{
	int infile = open(av[1], O_RDONLY);
	int	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int	new_pipe;
	int	pipe;

	for (int i = 2; i < ac - 1; i++)
	{
		if (i == 2)
			new_pipe = ft_execute_first_command(av[i], envp, infile);
		else if (i == ac - 2)
			ft_execute_last_command(av[i], envp, pipe, outfile);
		else
			new_pipe = ft_execute_middle_command(av[i], envp, pipe);
		pipe = new_pipe;
	}
	while (wait(NULL) > 0);
	return 0;
}

// TODO: Checking errors
// TODO: handle multiple pipes -> ac - 4 gives the number of needed
// TODO: Handle redirections
// TODO: Handle errors
// TODO: free all mallocs
