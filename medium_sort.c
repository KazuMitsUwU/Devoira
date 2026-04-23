/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:55 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/23 06:30:51 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*make_temp_arr(t_stack **stack_a, int size)
{
	int		*temp_arr;
	int		arr_i;
	t_stack	*layer;

	temp_arr = malloc(sizeof(int) * size);
	layer = *stack_a;
	arr_i = 0;
	while (layer)
	{
		temp_arr[arr_i] = layer->value;
		layer = layer->next;
		arr_i++;
	}
	return (temp_arr);
}

static void	sort_arr(int *temp_arr, int size)
{
	int	temp;
	int	arr_i;

	arr_i = 0;
	while (arr_i + 1 < size)
	{
		if (temp_arr[arr_i] <= temp_arr[arr_i + 1])
			arr_i++;
		else
		{
			temp = temp_arr[arr_i];
			temp_arr[arr_i] = temp_arr[arr_i + 1];
			temp_arr[arr_i + 1] = temp;
			arr_i = 0;
		}
	}
}

static void	define_positions(t_stack **stack_a, int *temp_arr, int size)
{
	int		arr_i;
	t_stack	*layer;

	layer = *stack_a;
	arr_i = 0;
	while (arr_i < size)
	{
		layer = *stack_a;
		while (layer)
		{
			if (temp_arr[arr_i] == layer->value && !layer->status)
			{
				layer->position = arr_i;
				layer->status = 1;
				break ;
			}
			else
				layer = layer->next;
		}
		arr_i++;
	}
}

static int	ft_sqrt(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

static void	chunk_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		chunk;
	int		nb_chunks;
	int		chunk_size;
	int		elements_in_chunk;
	int		chunk_start;
	int		chunk_end;

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
		elements_in_chunk = chunk_end - chunk_start;
		while (elements_in_chunk > 0)
		{
			if ((*stack_a)->position >= chunk_start && (*stack_a)->position < chunk_end)
			{
				pb(stack_a, stack_b);
				elements_in_chunk--;
			}
			else
				ra(stack_a);
		}
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

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
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


/*With 3 chunks on 500 numbers:

Each chunk has ~166 elements
To find the right element you rotate through up to 166 nodes each time
That's a lot of wasted moves

With √500 ≈ 11 chunks on 500 numbers:

Each chunk has ~45 elements
You rotate through at most 45 nodes to find the right element
Way fewer moves*/