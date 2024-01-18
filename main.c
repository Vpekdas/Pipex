/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/18 17:44:21 by vopekdas         ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	int		infile = open(av[1], O_RDONLY);
	int		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (ac > 4)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0) // child 1
		{
			close(fd[0]);
			dup2(infile, STDIN_FILENO); // it duplicates infile in STDIN, so we read infile.
			close(infile);
			dup2(fd[1], STDOUT_FILENO); // It duplicates pipe in STDOUT, so we are writing in pipe.
			close(fd[1]);
			ft_execute_commands(av[2], envp);
		}
		pid2 = fork();
		if (pid2 == 0) // child 2
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO); // It duplicates pipe out in STDIN. So we read the pipe.
			close(fd[0]);
			dup2(outfile, STDOUT_FILENO); // It duplicates outfile in STDOUT, sso we will write in outfile.
			close(outfile);
			ft_execute_commands(av[3], envp);
		}
		else // parent
		{
			close(fd[0]);
			close(fd[1]);
			close(infile);
			close(outfile);
			waitpid(pid, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

// TODO: Checking errors
// TODO: handle multiple pipes -> ac - 4 gives the number of needed
// TODO: Handle redirections
// TODO: Handle errors
// TODO: free all mallocs
