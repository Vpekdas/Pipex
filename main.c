/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/24 14:34:25 by vopekdas         ###   ########.fr       */
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
	if (ac > 4)
		infile = open(av[1], O_RDONLY);
	if (ac > 4 && ft_strncmp(av[1], "here_doc", 8) == 0 && infile != ERROR)
		ft_exec_here_doc(av, envp, av[ac - 1]);
	else if (ac > 4 && infile != ERROR)
	{
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
	return (0);
}
