/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:12:36 by manoaran          #+#    #+#             */
/*   Updated: 2026/04/21 15:19:46 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int		value;
	t_stack	*top_layer_a;
	t_stack	*top_layer_b;

	top_layer_a = *stack_a;
	top_layer_b = *stack_b;
	if (!stack_b || !top_layer_b)
		return ;
	value = top_layer_b->value;
	add_on_top(stack_a, value);
	if (top_layer_b->next)
	{
		top_layer_b = top_layer_b->next;
		free(top_layer_b->prev);
		top_layer_b->prev = NULL;
		*stack_b = top_layer_b;
	}
	else
	{
		free(top_layer_b);
		*stack_b = NULL;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	pa(stack_b, stack_a);
}
