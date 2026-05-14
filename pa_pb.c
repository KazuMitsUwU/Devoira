/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:12:36 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	t_stack	*top_b;

	if (!stack_b || !*stack_b)
		return ;
	top_b = *stack_b;
	add_on_top(stack_a, top_b->value);
	if (top_b->next)
	{
		top_b->next->prev = NULL;
		*stack_b = top_b->next;
	}
	else
		*stack_b = NULL;
	free(top_b);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
	print_op("pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	t_stack	*top_a;

	if (!stack_a || !*stack_a)
		return ;
	top_a = *stack_a;
	add_on_top(stack_b, top_a->value);
	if (top_a->next)
	{
		top_a->next->prev = NULL;
		*stack_a = top_a->next;
	}
	else
		*stack_a = NULL;
	free(top_a);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
	print_op("pb");
}
