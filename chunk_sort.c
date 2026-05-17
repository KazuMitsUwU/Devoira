/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:00:00 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/17 18:00:42 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench)
{
	int	min;

	while (*stack_b)
	{
		min = get_lowest_position(stack_b);
		if ((*stack_b)->next && (*stack_b)->next->position == min)
			sb(stack_b, bench);
		else
			while ((*stack_b)->position != min)
				rb(stack_b, bench);
		pa(stack_a, stack_b, bench);
	}
}

void	chunk_push(t_stack **stack_a, t_stack **stack_b,
					int size, t_bench *bench)
{
	int		chunk;
	int		nb_chunks;
	int		chunk_size;
	t_chunk	c;

	if (!stack_a || !*stack_a)
		return ;
	nb_chunks = ft_sqrt(size) / 2;
	if (nb_chunks < 1)
		nb_chunks = 1;
	chunk_size = size / nb_chunks;
	chunk = 1;
	while (chunk <= nb_chunks)
	{
		c.start = (chunk - 1) * chunk_size;
		if (chunk == nb_chunks)
			c.end = size;
		else
			c.end = chunk * chunk_size;
		process_chunk(stack_a, stack_b, c, bench);
		chunk++;
	}
}
