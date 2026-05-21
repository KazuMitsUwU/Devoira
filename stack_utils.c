/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:13:46 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/21 04:47:18 by sitrakaa         ###   ########.fr       */
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

int	get_max(t_stack **stack)
{
	t_stack	*layer;
	int		max;

	layer = *stack;
	max = layer->position;
	while (layer->next)
	{
		layer = layer->next;
		if (layer->position > max)
			max = layer->position;
	}
	return (max);
}
