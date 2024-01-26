/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:07 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/24 14:33:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_perror_msg(char *str)
{
	perror(str);
	return (ERROR);
}

int	ft_error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	return (ERROR);
}
