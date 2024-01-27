/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:45:51 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/27 14:29:53 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		infile;
	int		pipe;
	int		i;

	i = 1;
	pipe = 42;
	if (ac == 6 && ft_strcmp(av[1], "here_doc") == 0)
		ft_exec_here_doc(av, envp, av[ac - 1]);
	else if (ac > 4)
	{
		infile = open(av[1], O_RDONLY);
		if (infile == ERROR)
			return (ft_error_msg("Error: invalid input file\n"));
		while (++i < ac - 1 && pipe != ERROR && infile != ERROR)
		{
			if (i == 2)
				pipe = ft_exec_first_cmd(av[i], envp, infile);
			else if (i == ac - 2)
				pipe = ft_exec_last_cmd(av[i], envp, pipe, av[ac - 1]);
			else
				pipe = ft_exec_middle_cmd(av[i], envp, pipe);
		}
	}
	while (wait(NULL) > 0)
		;
}
// TODO: handle arguments error
// TODO: refactor main_bonus.c, too much lines