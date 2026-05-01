/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa sb ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:17:59 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/23 09:36:30 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int		temp;
	t_stack	*top_layer;

	if (!stack_a || !top_layer || !top_layer->next)
		return ;
	top_layer = *stack_a;
	temp = top_layer->value;
	top_layer->value = top_layer->next->value;
	top_layer->next->value = temp;
}

void	sb(t_stack **stack_b)
{
	sa(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sa(stack_b);
}
