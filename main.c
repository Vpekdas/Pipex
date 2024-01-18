/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/18 17:33:49 by vopekdas         ###   ########.fr       */
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
			dup2(infile, STDIN_FILENO); // read in infile instead of STDIN, it duplicates infile in STDIN
			close(infile);
			dup2(fd[1], STDOUT_FILENO); // write on pipe. It duplicates pipe entry in STDOUT
			close(fd[1]);
			ft_execute_commands(av[2], envp);
		}
		pid2 = fork();
		if (pid2 == 0) // child 2
		{
			close(fd[1]);
			dup2(outfile, STDOUT_FILENO); // write in outfile instead of STDOUT. It duplicates outfile in STDOUT
			close(outfile);
			dup2(fd[0], STDIN_FILENO); // read in pipe instead of STDIN. It duplicates pipe out in STDIN.
			close(fd[0]);
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
