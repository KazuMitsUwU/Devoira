/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:55 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/21 15:20:40 by sitrakaa         ###   ########.fr       */
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

static void	three_chunk_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		chunk;
	int		elements_in_chunk;
	int		chunk_start;
	int		chunk_end;
	t_stack	*layer;

	if (!stack_a || !*stack_a)
		return ;
	chunk = 1;
	while (layer && chunk <= 3)
	{
		while (elements_in_chunk > 0)
		{
			layer = *stack_a;
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

}
