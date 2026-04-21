/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:57:15 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 17:06:28 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> checks if current node exists;
	=> checks if next node exists and counting each node until none is found; 
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		n_node;

	if (!lst)
		return (0);
	node = lst;
	n_node = 0;
	while (node)
	{
		n_node++;
		node = node->next;
	}
	return (n_node);
}
