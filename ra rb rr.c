/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra rb rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:15:50 by manoaran          #+#    #+#             */
/*   Updated: 2026/04/15 14:31:01 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	int		value;
	t_stack	*top_layer;
	t_stack	*bot_layer;
	t_stack	*old_top;

	top_layer = *stack_a;
	if (!top_layer || !top_layer->next)
		return ;
	value = top_layer->value;
	add_at_bot(stack_a, value);
	top_layer = top_layer->next;
	old_top = top_layer->prev;
	*stack_a = top_layer;
	top_layer->prev = NULL;
	free(old_top);
}

void	rb(t_stack **stack_b)
{
	ra(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	ra(stack_b);
}
