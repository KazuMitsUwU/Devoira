/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:17:38 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/28 10:54:48 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack *stack_a)
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

static int	nb_ra(t_stack *stack_a, int min_value)
{
	int	nb_of_ra;

	nb_of_ra = 0;
	while (stack_a)
	{
		if (stack_a->value == min_value)
			break ;
		stack_a = stack_a->next;
		nb_of_ra++;
	}
	return (nb_of_ra);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min_value;
	int	rotations;

	while (*stack_a)
	{
		min_value = get_min(*stack_a);
		rotations = nb_ra(*stack_a, min_value);
		while (rotations > 0)
		{
			ra(stack_a);
			rotations--;
		}
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
