/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:56:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putstr_fd.c: Outputs the string `s` to the given file descriptor. */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (print_error_void(STR_NULL_ERROR));
	write(fd, s, ft_strlen(s));
}
