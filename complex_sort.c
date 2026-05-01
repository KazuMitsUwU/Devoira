/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:51 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/28 11:08:44 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_stack **stack_a, t_stack **stack_b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*stack_a)->position >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		max_bits;
	int		bit;
	int		*temp_arr;

	size = nb_of_layer(stack_a);
	temp_arr = make_temp_arr(stack_a, size);
	sort_arr(temp_arr, size);
	define_positions(stack_a, temp_arr, size);
	free(temp_arr);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(stack_a, stack_b, bit, size);
		bit++;
	}
}
