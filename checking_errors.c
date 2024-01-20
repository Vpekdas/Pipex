/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:25:13 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/20 15:41:48 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_pipe(void)
{
	perror("ERROR PIPE");
	return (-1);
}

int	ft_check_fork(void)
{
	perror("ERROR FORK");
	return (-1);
}

int	ft_check_execve(void)
{
	perror("ERROR EXECVE");
	return (-1);
}
