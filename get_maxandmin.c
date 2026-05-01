/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maxandmin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:36:42 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/23 09:37:04 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack_a)
{
	int	min_value;

	min_value = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min_value)
			min_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min_value);
}

int	get_max_position(t_stack **stack_b)
{
	t_stack	*layer;
	int		max;

	layer = *stack_b;
	max = layer->position;
	while (layer)
	{
		if (layer->position > max)
			max = layer->position;
		layer = layer->next;
	}
	return (max);
}
