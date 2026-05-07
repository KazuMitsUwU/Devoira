/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:55 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/07 09:54:14 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunk(t_combine *c, int chunk_start, int chunk_end)
{
	int	elements_in_chunk;

	elements_in_chunk = chunk_end - chunk_start;
	while (elements_in_chunk > 0)
	{
		if ((*c->stack_a)->position >= chunk_start
			&& (*c->stack_a)->position < chunk_end)
		{
			pb(c);
			elements_in_chunk--;
		}
		else
			ra(c);
	}
}

static void	chunk_push(t_combine *c, int size)
{
	int	chunk;
	int	nb_chunks;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (!c->stack_a || !*c->stack_a)
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
		process_chunk(c, chunk_start, chunk_end);
		chunk++;
	}
}

static void	push_back_to_a(t_combine *c)
{
	int	max;

	while (*c->stack_b)
	{
		max = get_max_position(c->stack_b);
		while ((*c->stack_b)->position != max)
			rb(c);
		pa(c);
	}
}

void	chunk_based_sort(t_combine *c)
{
	int	initial_size;
	int	*temp_arr;

	if (!c->stack_a || !*c->stack_a)
		return ;
	initial_size = nb_of_layer(c->stack_a);
	temp_arr = make_temp_arr(c->stack_a, initial_size);
	sort_arr(temp_arr, initial_size);
	define_positions(c->stack_a, temp_arr, initial_size);
	free(temp_arr);
	chunk_push(c, initial_size);
	push_back_to_a(c);
}
