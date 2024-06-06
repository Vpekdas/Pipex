/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:56:13 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putchar_fd.c: Outputs the character `c` to the given file descriptor. */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (!c)
		return (print_error_void(STR_NULL_ERROR));
	if (write(fd, &c, 1) == ERROR)
		return (print_error_void(WRITE_ERROR));
}
