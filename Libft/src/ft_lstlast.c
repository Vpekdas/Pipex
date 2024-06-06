/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:37:05 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:20:37 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstlast.c: Returns the last element of the list. */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst)
		return (NULL);
	current = lst;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}
