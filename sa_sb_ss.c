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

void	sa(t_stack **stack_a)
{
	int		temp;
	t_stack	*top_layer;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	top_layer = *stack_a;
	temp = top_layer->value;
	top_layer->value = top_layer->next->value;
	top_layer->next->value = temp;
	print_op("sa");
}

void	sb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	sa(stack_b);
	print_op("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sa(stack_b);
	print_op("ss");
}
