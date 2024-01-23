/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:09 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/23 17:29:49 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_here_doc(char **av, char **envp, char *out_path)
{
	char	*limiter;
	int		here_doc;
	char	*temp;
	int		pipe;

	limiter = av[2];
	here_doc = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	temp = NULL;
	pipe = 42;
	while (1)
	{
		temp = get_next_line(0);
		write (here_doc, temp, ft_strlen(temp));
		if (ft_strncmp(temp, limiter, ft_strlen(limiter)) == 0)
			break ;
	}
	close(here_doc);
	here_doc = open("here_doc", O_RDONLY);
	pipe = ft_exec_first_cmd(av[3], envp, here_doc);
	ft_exec_last_cmd(av[4], envp, pipe, out_path);
	close(here_doc);
}
