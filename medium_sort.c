/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:26 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/17 17:04:20 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
