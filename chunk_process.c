/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:00:00 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/17 00:00:00 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_in_chunk(t_stack **stack_a, t_chunk chunk)
{
	t_stack	*curr;
	int		count;

	curr = *stack_a;
	count = 0;
	while (curr)
	{
		if (curr->position >= chunk.start && curr->position < chunk.end)
			count++;
		curr = curr->next;
	}
	return (count);
}

static int	try_push_top(t_stack **stack_a, t_stack **stack_b,
						t_chunk chunk, t_bench *bench)
{
	if ((*stack_a)->position >= chunk.start
		&& (*stack_a)->position < chunk.end)
	{
		pb(stack_a, stack_b, bench);
		return (1);
	}
	if ((*stack_a)->next
		&& (*stack_a)->next->position >= chunk.start
		&& (*stack_a)->next->position < chunk.end)
	{
		sa(stack_a, bench);
		pb(stack_a, stack_b, bench);
		return (1);
	}
	return (0);
}

static void	rotate_pass(t_stack **stack_a, t_stack **stack_b,
						t_chunk chunk, t_bench *bench)
{
	int	stack_size;
	int	rotations;

	stack_size = nb_of_layer(stack_a);
	rotations = 0;
	while (rotations < stack_size)
	{
		if (try_push_top(stack_a, stack_b, chunk, bench))
			return ;
		ra(stack_a, bench);
		rotations++;
	}
}

void	process_chunk(t_stack **stack_a, t_stack **stack_b,
					t_chunk chunk, t_bench *bench)
{
	int	elements_in_chunk;

	elements_in_chunk = count_in_chunk(stack_a, chunk);
	while (elements_in_chunk > 0)
	{
		rotate_pass(stack_a, stack_b, chunk, bench);
		elements_in_chunk = count_in_chunk(stack_a, chunk);
	}
}
