/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:51 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/07 09:51:40 by sitrakaa         ###   ########.fr       */
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

static void	init_positions(t_stack **stack_a, int size)
{
	int	*temp_arr;

	temp_arr = make_temp_arr(stack_a, size);
	sort_arr(temp_arr, size);
	define_positions(stack_a, temp_arr, size);
	free(temp_arr);
}

static void	radix_pass(t_combine *c, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*c->stack_a)->position >> bit) & 1)
		{
			ra(c->stack_a);
			c->bench->ra++;
		}
		else
		{
			pb(c);
		}
		i++;
	}
	while (*c->stack_b)
		pa(c);
}

void	radix_sort(t_combine *c)
{
	int	size;
	int	bit;

	size = nb_of_layer(c->stack_a);
	init_positions(c->stack_a, size);
	bit = 0;
	while (bit < get_max_bits(size))
	{
		radix_pass(c, bit, size);
		bit++;
	}
}
