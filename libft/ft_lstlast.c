/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:15:49 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 16:28:33 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> creates a pointer that is going to find te last node by incrementation;
	=> returns the pointer;
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}
