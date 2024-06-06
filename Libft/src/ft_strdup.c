/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:46 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:18:28 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strdup.c: Returns a pointer to a new string which is a duplicate 
** of the string `s`. */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	if (!s1)
		return (print_error_char(STR_NULL_ERROR));
	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (print_error_char(MALLOC_ERROR));
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
