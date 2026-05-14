/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:00:00 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, t_bench *bench)
{
	t_stack	*top;
	t_stack	*bot;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	top = *stack_a;
	*stack_a = top->next;
	(*stack_a)->prev = NULL;
	bot = *stack_a;
	while (bot->next)
		bot = bot->next;
	top->prev = bot;
	top->next = NULL;
	bot->next = top;
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
	print_op("ra");
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	t_stack	*top;
	t_stack	*bot;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	top = *stack_b;
	*stack_b = top->next;
	(*stack_b)->prev = NULL;
	bot = *stack_b;
	while (bot->next)
		bot = bot->next;
	top->prev = bot;
	top->next = NULL;
	bot->next = top;
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
	print_op("rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ra(stack_a, NULL);
	rb(stack_b, NULL);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
	print_op("rr");
}
