/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_multi_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:51:35 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/29 10:51:36 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_handle_multi_pipe(int ac, char **av, char **envp)
{
	int		infile;
	int		pipe;
	int		i;

	i = 1;
	pipe = 42;
	infile = open(av[1], O_RDONLY);
	if (infile == ERROR)
		return (ft_perror_msg("Error: input file not found"));
	while (++i < ac - 1 && pipe != ERROR && infile != ERROR)
	{
		if (i == 2)
			pipe = ft_exec_first_cmd(av[i], envp, infile);
		else if (i == ac - 2)
			pipe = ft_exec_last_cmd(av[i], envp, pipe, av[ac - 1]);
		else
			pipe = ft_exec_middle_cmd(av[i], envp, pipe);
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
