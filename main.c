/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/20 18:18:43 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;
	int	pipe;
	int	i;

	i = 2;
	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ac > 4 && infile != -1 && outfile != -1)
	{
		while (i < ac - 1 && pipe != -1)
		{
			if (i == 2)
				pipe = ft_exec_first_cmd(av[i], envp, infile);
			else if (i == ac - 2)
				pipe = ft_exec_last_cmd(av[i], envp, pipe, outfile);
			else
				pipe = ft_exec_middle_cmd(av[i], envp, pipe);
			i++;
		}
		while (wait(NULL) > 0)
			;
		ft_close_end(pipe, outfile, infile);
	}
	return (0);
}

// TODO: Handle redirections
// TODO: free all mallocs