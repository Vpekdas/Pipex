/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:08:31 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/16 17:13:07 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>

int	checking_errors_pid(pid_t pid)
{
	if (pid == -1)
	{
		perror("fork");
		return (2);	
	}
	return (0);
}

int	checking_errors_pipe(int pipe)
{
	if (pipe == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}
