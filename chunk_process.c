/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:00:00 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/21 00:12:38 by manoaran         ###   ########.fr       */
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

static int	find_chunk_member(t_stack **stack_a, t_chunk chunk)
{
	t_stack	*current;
	int		index;

	current = *stack_a;
	index = 0;
	while (current)
	{
		if (current->position >= chunk.start && current->position < chunk.end)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

static void	rotate_pass(t_stack **stack_a, t_stack **stack_b,
						t_chunk chunk, t_bench *bench)
{
	int	size;
	int	closest;
	int	i;

	size = nb_of_layer(stack_a);
	closest = find_chunk_member(stack_a, chunk);
	if (closest == -1)
		return ;
	i = 0;
	if (closest <= size / 2)
	{
		while (i++ < closest)
			ra(stack_a, bench);
	}
	else
	{
		while (i++ < size - closest)
			rra(stack_a, bench);
	}
	pb(stack_a, stack_b, bench);
}

void	process_chunk(t_stack **stack_a, t_stack **stack_b,
					t_chunk chunk, t_bench *bench)
{
	int	elements_in_chunk;

	elements_in_chunk = count_in_chunk(stack_a, chunk);
	while (elements_in_chunk--)
		rotate_pass(stack_a, stack_b, chunk, bench);
}
