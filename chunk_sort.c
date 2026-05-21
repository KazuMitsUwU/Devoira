/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:00:00 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/21 04:10:11 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench)
{
	int		max;
	int		max_depth;
	int		size;
	t_stack	*current;

	while (*stack_b)
	{
		max = get_max(stack_b);
		size = nb_of_layer(stack_b);
		max_depth = 0;
		current = *stack_b;
		while (current->position != max)
		{
			current = current->next;
			max_depth++;
		}
		if (max_depth < size / 2)
			while ((*stack_b)->position != max)
				rb(stack_b, bench);
		else
			while ((*stack_b)->position != max)
				rrb(stack_b, bench);
		pa(stack_a, stack_b, bench);
	}
}

void	chunk_push(t_stack **stack_a, t_stack **stack_b,
					int size, t_bench *bench)
{
	int		block_size;
	int		block_num;
	int		i;
	int		size_a;

	block_size = ft_sqrt(size);
	block_num = block_size;
	while (*stack_a)
	{
		i = 0;
		size_a = nb_of_layer(stack_a);
		while (i++ < size_a)
		{
			if ((*stack_a)->position < block_num)
				pb(stack_a, stack_b, bench);
			else
				ra(stack_a, bench);
		}
		block_num += block_size;
	}
}
