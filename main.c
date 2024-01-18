/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/18 14:56:07 by vopekdas         ###   ########.fr       */
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
	int		infile = open(av[1], O_RDONLY);
	int		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (ac > 4)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0) // child 1
		{
			close(fd[0]);
			dup2(infile, STDIN_FILENO);
			close(infile);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			args = ft_split(av[2], ' ');
			cmd1 = ft_create_path(args[0], envp);
			execve(cmd1, args, envp);
		}
		pid2 = fork();
		if (pid2 == 0) // child 2
		{
			close(fd[1]);
			dup2(outfile, STDOUT_FILENO);
			close(outfile);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			args2 = ft_split(av[3], ' ');
			cmd2 = ft_create_path(args2[0], envp);
			execve(cmd2, args2, envp);
		}
		else // parent
		{
			close(fd[1]);
			close(fd[0]);
			close(infile);
			close(outfile);
			waitpid(pid, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

// TODO: Checking errors
// TODO: handle multiple pipes
// TODO: Handle redirections
// TODO: Handle errors
// TODO: free all mallocs
