/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:42 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:19:58 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstclear.c: Deletes and frees the given element and every successor
** of that element. */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
