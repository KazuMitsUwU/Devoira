/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:17:38 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	min_value;
	int	rotations;

	while (*stack_a)
	{
		min_value = get_min_value(*stack_a);
		rotations = nb_ra(*stack_a, min_value);
		while (rotations > 0)
		{
			ra(stack_a, bench);
			rotations--;
		}
		pb(stack_a, stack_b, bench);
	}
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}
