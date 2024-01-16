/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/16 17:25:48 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	char	*cmd1 = NULL;
	char	*cmd2 = NULL;
	char	**args = NULL;
	char	**args2 = NULL;

	if (ac < 2)
		return (0);
	pipe(fd);
	if (checking_errors_pipe(fd[0]) || checking_errors_pipe(fd[1]))
		return (1);
	pid = fork();
	if (checking_errors_pid(pid))
		return (2);
	if (pid == 0) // child 1
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		args = ft_split(av[1], ' ');
		cmd1 = ft_create_path(ac, args[0], envp);
		execve(cmd1, args, NULL);
	}
	pid2 = fork();
	if (checking_errors_pid(pid2))
		return (1);
	if (pid2 == 0) // child 2
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		args2 = ft_split(av[2], ' ');
		cmd2 = ft_create_path(ac, args2[0], envp);
		execve(cmd2, args2, NULL);
	}
	else // parent
	{
		close(fd[1]);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

// TODO: Handle infile and outfile
// TODO: Handle redirections
// TODO: Handle errors
// TODO: handle multiple pipes
// TODO: free all mallocs
