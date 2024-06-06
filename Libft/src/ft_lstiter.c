/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:36:15 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:20:25 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstiter.c: Iterates the list `lst` and applies the function `f` 
** to the content of each element. */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		(*f)(&current->content);
		current = current->next;
	}
}
