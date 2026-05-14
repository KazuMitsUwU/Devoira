/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:14:53 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, t_bench *bench)
{
	t_stack	*bot_layer;
	t_stack	*old_bot;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	bot_layer = *stack_a;
	while (bot_layer->next)
		bot_layer = bot_layer->next;
	add_on_top(stack_a, bot_layer->value);
	old_bot = bot_layer;
	bot_layer->prev->next = NULL;
	free(old_bot);
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
	print_op("rra");
}

void	rrb(t_stack **stack_b, t_bench *bench)
{
	t_stack	*bot_layer;
	t_stack	*old_bot;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	bot_layer = *stack_b;
	while (bot_layer->next)
		bot_layer = bot_layer->next;
	add_on_top(stack_b, bot_layer->value);
	old_bot = bot_layer;
	bot_layer->prev->next = NULL;
	free(old_bot);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
	print_op("rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rra(stack_a, NULL);
	rrb(stack_b, NULL);
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
	print_op("rrr");
}
