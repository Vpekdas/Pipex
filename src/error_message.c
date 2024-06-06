/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:07 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/06 01:27:38 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_perror_msg(void)
{
	perror("");
	return (ERROR);
}

int	ft_error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	return (ERROR);
}

int	ft_error_msg_bash(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	return (ERROR);
}

int	ft_error_msg_command(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("command not found\n", 2);
	return (ERROR);
}
