/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:17:59 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/17 17:17:59 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, t_bench *bench)
{
	int		temp;
	t_stack	*top_layer;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	top_layer = *stack_a;
	temp = top_layer->value;
	top_layer->value = top_layer->next->value;
	top_layer->next->value = temp;
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
	print_op("sa");
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	sa(stack_b, bench);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
	print_op("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	sa(stack_a, bench);
	sa(stack_b, bench);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
	print_op("ss");
}

