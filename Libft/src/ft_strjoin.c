/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:39:07 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strjoin.c: Allocates and returns a new string, which is the result
** of the concatenation of `s1` and `s2`. */

#include "../includes/libft.h"

static char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	len;

	i = 0;
	if (!dest || !src)
		return (print_error_char(STR_NULL_ERROR));
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (print_error_char(MALLOC_ERROR));
	ft_memset(ptr, '\0', len);
	ft_strcat(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}
