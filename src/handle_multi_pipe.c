/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_multi_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:51:35 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/06 01:58:07 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_handle_multi_pipe(int ac, char **av, char **envp)
{
	int		infile;
	int		pipe;
	int		i;

	i = 1;
	pipe = 42;
	infile = open(av[1], O_RDONLY);
	if (infile == ERROR)
		ft_error_msg_bash(av[1]);
	while (++i < ac - 1 && pipe != ERROR)
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
