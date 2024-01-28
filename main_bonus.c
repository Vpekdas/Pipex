/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:45:51 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/27 18:08:45 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 6 && ft_strcmp(av[1], "here_doc") == 0)
		ft_exec_here_doc(av, envp, av[ac - 1]);
	else if (ac > 4)
		return (ft_handle_multi_pipe(ac, av, envp));
	else
		return (ft_error_msg("Error: expected 4 arguments\n"));
	while (wait(NULL) > 0)
		;
}
