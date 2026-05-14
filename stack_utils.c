/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:13:46 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_of_layer(t_stack **stack)
{
	t_stack	*layer;
	int		size;

	if (!stack || !*stack)
		return (0);
	layer = *stack;
	size = 0;
	while (layer)
	{
		size++;
		layer = layer->next;
	}
	return (size);
}

void	add_on_top(t_stack **stack, int value)
{
	t_stack	*new_top;

	new_top = malloc(sizeof(t_stack));
	if (!new_top)
		return ;
	new_top->value = value;
	new_top->position = 0;
	new_top->status = 0;
	new_top->prev = NULL;
	new_top->next = *stack;
	if (*stack)
		(*stack)->prev = new_top;
	*stack = new_top;
}

void	add_at_bot(t_stack **stack, int value)
{
	t_stack	*new_bot;
	t_stack	*bot;

	new_bot = malloc(sizeof(t_stack));
	if (!new_bot)
		return ;
	new_bot->value = value;
	new_bot->position = 0;
	new_bot->status = 0;
	new_bot->next = NULL;
	new_bot->prev = NULL;
	if (!*stack)
	{
		*stack = new_bot;
		return ;
	}
	bot = *stack;
	while (bot->next)
		bot = bot->next;
	bot->next = new_bot;
	new_bot->prev = bot;
}

int	get_min_value(t_stack *stack_a)
{
	int	min_value;

	min_value = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min_value)
			min_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min_value);
}

int	get_lowest_position(t_stack **stack_b)
{
	t_stack	*layer;
	int		lowest;

	layer = *stack_b;
	lowest = layer->position;
	while (layer)
	{
		if (layer->position < lowest)
			lowest = layer->position;
		layer = layer->next;
	}
	return (lowest);
}
