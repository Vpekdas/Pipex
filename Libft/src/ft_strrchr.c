/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:55 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strrchr.c: Locates the last occurrence of `c` (converted to a char)
** in the string pointed to by `s`. */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (print_error_char(STR_NULL_ERROR));
	i = ft_strlen(s) - 1;
	ch = (char) c;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i--;
	}
	if (ch == 0)
		return ((char *)(s + ft_strlen(s)));
	return (NULL);
}
