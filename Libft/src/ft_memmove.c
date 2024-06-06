/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:34 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_memmove.c: Copies `n` bytes from `src` to `dest`, but is safe for 
** overlapping memory areas. */

#include "../includes/libft.h"

static	void	overlap(unsigned char *dst, unsigned const char *src, size_t n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	i = 0;
	if (!dst || !src)
		return (print_error_char(STR_NULL_ERROR));
	dest = dst;
	source = src;
	if (dest > source)
		overlap(dest, source, n);
	else
	{
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dest);
}
