/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:51 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/19 08:33:52 by sitrakaa         ###   ########.fr       */
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

static void	radix_pass(t_stack **stack_a, t_stack **stack_b,
						int size, t_bench *bench)
{
	int	i;
	int	bit;

	bit = 0;
	while (bit < get_max_bits(size))
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->position >> bit) & 1)
				ra(stack_a, bench);
			else
				pb(stack_a, stack_b, bench);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, bench);
		bit++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int		size;
	int		*temp_arr;

	size = nb_of_layer(stack_a);
	temp_arr = make_temp_arr(stack_a, size);
	sort_arr(temp_arr, size);
	define_positions(stack_a, temp_arr, size);
	free(temp_arr);
	radix_pass(stack_a, stack_b, size, bench);
}
