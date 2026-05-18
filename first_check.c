/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:18:53 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/18 17:36:02 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_already_sorted(t_stack **stack)
{
	t_stack	*layer;
	int		value;

	layer = *stack;
	if (!layer)
		return (0);
	while (layer->next)
	{
		value = layer->value;
		layer = layer->next;
		if (value > layer->value)
			return (0);
	}
	return (1);
}

void	check_if_sorted(t_stack **stack_a)
{
	int	check;

	if (!stack_a)
		return ;
	check = is_already_sorted(stack_a);
	if (check)
	{
		free_stack (stack_a);
		exit(0);
	}
	return ;
}
