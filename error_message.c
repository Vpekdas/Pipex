/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:07 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/03 16:55:14 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
