/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:01 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strlcpy.c: Copies up to `size - 1` characters from the null-terminated
** string `src` to `dst`, null-terminating the result. */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (print_error_int(STR_NULL_ERROR));
	while (src[i])
	{
		if ((i < size - 1 && size != 0))
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	if (size != 0)
		dst[j] = '\0';
	return (i);
}
