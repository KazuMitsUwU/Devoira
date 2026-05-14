/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:26 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 04:15:21 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunk(t_stack **stack_a, t_stack **stack_b,
							int chunk_start, int chunk_end,
								t_bench *bench)
{
	int	elements_in_chunk;

	elements_in_chunk = chunk_end - chunk_start;
	while (elements_in_chunk > 0)
	{
		if ((*stack_a)->position >= chunk_start
			&& (*stack_a)->position < chunk_end)
		{
			pb(stack_a, stack_b, bench);
			elements_in_chunk--;
		}
		else
			ra(stack_a, bench);
	}
}

static void	chunk_push(t_stack **stack_a, t_stack **stack_b,
						int size, t_bench *bench)
{
	int	chunk;
	int	nb_chunks;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (!stack_a || !*stack_a)
		return ;
	nb_chunks = ft_sqrt(size) / 2;
	if (nb_chunks < 1)
		nb_chunks = 1;
	chunk_size = size / nb_chunks;
	chunk = 1;
	while (chunk <= nb_chunks)
	{
		chunk_start = (chunk - 1) * chunk_size;
		if (chunk == nb_chunks)
			chunk_end = size;
		else
			chunk_end = chunk * chunk_size;
		process_chunk(stack_a, stack_b, chunk_start, chunk_end, bench);
		chunk++;
	}
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b,
							t_bench *bench)
{
	int	min;

	while (*stack_b)
	{
		min = get_lowest_position(stack_b);
		while ((*stack_b)->position != min)
			rb(stack_b, bench);
		pa(stack_a, stack_b, bench);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
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
	chunk_push(stack_a, stack_b, initial_size, bench);
	push_back_to_a(stack_a, stack_b, bench);
}
