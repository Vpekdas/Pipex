/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:16 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strnstr.c: Locates the first occurrence of the null-terminated string
** `needle` in the string `haystack`, where not more than `len` 
** characters are searched. */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (print_error_char(STR_NULL_ERROR));
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	if (len == 0)
		return (NULL);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
