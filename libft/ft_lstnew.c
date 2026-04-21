/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 07:44:00 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 10:55:05 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> allocates mem for a new node storing the data passed as parameter 
		and returns it, setting next element to null;
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node_with_content;

	node_with_content = malloc(sizeof(t_list));
	if (!node_with_content)
		return (NULL);
	node_with_content->content = content;
	node_with_content->next = NULL;
	return (node_with_content);
}
