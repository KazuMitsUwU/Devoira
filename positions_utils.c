/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:41:43 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/28 10:22:28 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_temp_arr(t_stack **stack_a, int size)
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

void	sort_arr(int *temp_arr, int size)
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

void	define_positions(t_stack **stack_a, int *temp_arr, int size)
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

int	ft_sqrt(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}
