/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/03 16:55:28 by vopekdas         ###   ########.fr       */
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
	if (ac != 5)
		return (ft_error_msg("Error: expected 4 arguments\n"));
	infile = open(av[1], O_RDONLY);
	if (infile == ERROR)
		(ft_perror_msg());
	while (++i < ac - 1 && pipe != ERROR)
	{
		if (i == 2)
			pipe = ft_exec_first_cmd(av[i], envp, infile);
		else
			pipe = ft_exec_last_cmd(av[i], envp, pipe, av[ac - 1]);
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
