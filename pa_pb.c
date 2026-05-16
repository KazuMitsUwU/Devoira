/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:12:36 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/15 06:36:36 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	t_stack	*top_b;

	if (!stack_b || !*stack_b)
		return ;
	top_b = *stack_b;
	if (top_b->next)
	{
		top_b->next->prev = NULL;
		*stack_b = top_b->next;
	}
	else
		*stack_b = NULL;
	top_b->next = *stack_a;
	top_b->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = top_b;
	*stack_a = top_b;
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
	if (top_a->next)
	{
		top_a->next->prev = NULL;
		*stack_a = top_a->next;
	}
	else
		*stack_a = NULL;
	top_a->next = *stack_b;
	top_a->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = top_a;
	*stack_b = top_a;
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
	print_op("pb");
}
