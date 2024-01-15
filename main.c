/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/15 17:31:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	char	*cmd1;
	char	*cmd2;
	char	**args;
	char	**args2;

	(void)av;
	(void)envp;
	(void)ac;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0) // child 1
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		cmd1 = ft_strdup("/bin/ls");
		args = ft_split("ls -l", ' ');
		execve(cmd1, args, NULL);
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid2 == 0) // child 2
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		cmd2 = ft_strdup("/usr/bin/grep");
		args2 = ft_split("grep main", ' ');
		execve(cmd2, args2, NULL);
	}
	else // parent
	{
		close(fd[1]);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

// TODO: Create a function that parse the command and return path
// TODO: Modify the child process code to use the new function
// TODO: Handle multiple commands
// TODO: Handle redirections
// TODO: Handle errors
// TODO: handle commands with arguments
// TODO: handle pipes
// TODO: free all mallocs
