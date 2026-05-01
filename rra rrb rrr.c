/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra rrb rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:14:53 by manoaran          #+#    #+#             */
/*   Updated: 2026/04/23 09:36:29 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	int		value;
	t_stack	*bot_layer;
	t_stack	*old_bot;

	bot_layer = *stack_a;
	if (!bot_layer || !bot_layer->next)
		return ;
	while (bot_layer->next)
		bot_layer = bot_layer->next;
	value = bot_layer->value;
	add_on_top(stack_a, value);
	bot_layer = bot_layer->prev;
	old_bot = bot_layer->next;
	bot_layer->next = NULL;
	free(old_bot);
}

void	rrb(t_stack **stack_b)
{
	rra(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rra(stack_b);
}
