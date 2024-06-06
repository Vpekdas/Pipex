/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:45:51 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/06 01:55:40 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_here	here_doc;

	here_doc = (t_here){0};
	if (ac == 6 && ft_strcmp(av[1], "here_doc") == 0)
	{
		here_doc.fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (here_doc.fd == ERROR)
			return (ft_perror_msg());
		here_doc.limiter = av[2];
		ft_exec_here_doc(av, envp, av[ac - 1], &here_doc);
	}
	else if (ac > 4)
		return (ft_handle_multi_pipe(ac, av, envp));
	else
		return (ft_error_msg("Error: expected 4 arguments\n"));
	while (wait(NULL) > 0)
		;
	return (0);
}
