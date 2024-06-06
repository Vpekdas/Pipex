/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:51 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/04 04:20:11 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstdelone.c: Takes as a parameter an element and frees the memory 
** of the element’s content using the function `del` given as a parameter 
** and free the element. */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int*))
{
	if (!del || !lst)
		return ;
	del(&lst->content);
	free(lst);
}
