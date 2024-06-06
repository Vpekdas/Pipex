/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:32:19 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:28 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* ft_atoi.c: Converts the initial portion of the string pointed to by `str` 
** to an integer. */

int	print_error_int(char *error_message)
{
	if (error_message != NULL)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(error_message, 2);
		ft_putstr_fd(NC, 2);
	}
	return (ERROR);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str)
		return (print_error_int(STR_NULL_ERROR));
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return (result * sign);
}
