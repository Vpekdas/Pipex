/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:57:09 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strchr.c: Locates the first occurrence of `c` (converted to a char)
** in the string pointed to by `s`. */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (print_error_char(STR_NULL_ERROR));
	ch = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (ch == 0)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
