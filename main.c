/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/23 16:31:56 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		infile;
	char	*outfile;
	int		pipe;
	int		i;

	i = 1;
	pipe = 42;
	infile = open(av[1], O_RDONLY);
	outfile = av[ac - 1];
	if (ac > 4 && ft_strncmp(av[1], "here_doc", 8) == 0)
		ft_exec_here_doc(av, envp, outfile);
	else if (ac > 4 && infile != ERROR)
	{
		while (++i < ac - 1 && pipe != ERROR && infile != ERROR)
		{
			if (i == 2)
				pipe = ft_exec_first_cmd(av[i], envp, infile);
			else if (i == ac - 2)
				pipe = ft_exec_last_cmd(av[i], envp, pipe, outfile);
			else
				pipe = ft_exec_middle_cmd(av[i], envp, pipe);
		}
		while (wait(NULL) > 0)
			;
	}
	return (0);
}

// TODO: Handle here_doc