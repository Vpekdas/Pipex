/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:45:51 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/25 14:59:54 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		pipe;
	int		i;

	i = 1;
	pipe = 42;
	if (ac > 4 && ft_strcmp(av[1], "here_doc") == 0)
		ft_exec_here_doc(av, envp, av[ac - 1]);
	else
		ft_putstr_fd("Error, arguments are less than 5\n", 2);
	while (wait(NULL) > 0)
		;
	return (0);
}
