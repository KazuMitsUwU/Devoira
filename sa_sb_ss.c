/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:17:59 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack **stack)
{
	int		temp;
	t_stack	*top_layer;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	top_layer = *stack;
	temp = top_layer->value;
	top_layer->value = top_layer->next->value;
	top_layer->next->value = temp;
}

void	sa(t_stack **stack_a, t_bench *bench)
{
	swap_top(stack_a);
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
	print_op("sa");
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	swap_top(stack_b);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
	print_op("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	swap_top(stack_a);
	swap_top(stack_b);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
	print_op("ss");
}
