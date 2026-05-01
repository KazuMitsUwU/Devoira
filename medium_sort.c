/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:55 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/28 10:50:49 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunk(t_stack **stack_a, t_stack **stack_b,
							int chunk_start, int chunk_end)
{
	int	elements_in_chunk;

	elements_in_chunk = chunk_end - chunk_start;
	while (elements_in_chunk > 0)
	{
		if ((*stack_a)->position >= chunk_start
			&& (*stack_a)->position < chunk_end)
		{
			pb(stack_a, stack_b);
			elements_in_chunk--;
		}
		else
			ra(stack_a);
	}
}

static void	chunk_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk;
	int	nb_chunks;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (!stack_a || !*stack_a)
		return ;
	nb_chunks = ft_sqrt(size) / 2;
	chunk_size = size / nb_chunks;
	chunk = 1;
	while (chunk <= nb_chunks)
	{
		chunk_start = (chunk - 1) * chunk_size;
		if (chunk == nb_chunks)
			chunk_end = size;
		else
			chunk_end = chunk * chunk_size;
		process_chunk(stack_a, stack_b, chunk_start, chunk_end);
		chunk++;
	}
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		max;

	while (*stack_b)
	{
		max = get_max_position(stack_b);
		while ((*stack_b)->position != max)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	chunk_based_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		initial_size;
	int		*temp_arr;

	if (!stack_a || !*stack_a)
		return ;
	initial_size = nb_of_layer(stack_a);
	temp_arr = make_temp_arr(stack_a, initial_size);
	sort_arr(temp_arr, initial_size);
	define_positions(stack_a, temp_arr, initial_size);
	free(temp_arr);
	chunk_push(stack_a, stack_b, initial_size);
	push_back_to_a(stack_a, stack_b);
}
