/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:13:46 by manoaran          #+#    #+#             */
/*   Updated: 2026/04/28 10:59:59 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_of_layer(t_stack **stack)
{
	t_stack	*layer;
	int		size;

	if (!layer)
		return (0);
	layer = *stack;
	size = 1;
	while (layer->next)
	{
		layer = layer->next;
		size++;
	}
	return (size);
}

void	add_on_top(t_stack **stack, int value)
{
	t_stack	*top_layer;
	t_stack	*new_top_layer;

	top_layer = *stack;
	new_top_layer = malloc(sizeof(t_stack));
	if (!new_top_layer)
		return ;
	new_top_layer->value = value;
	if (top_layer)
	{
		new_top_layer->next = top_layer;
		top_layer->prev = new_top_layer;
		*stack = new_top_layer;
	}
	else
		top_layer = new_top_layer;
}

void	add_at_bot(t_stack **stack, int value)
{
	t_stack	*bot_layer;
	t_stack	*new_bot_layer;

	bot_layer = *stack;
	while (bot_layer->next)
		bot_layer = bot_layer->next;
	new_bot_layer = malloc(sizeof(t_stack));
	if (!new_bot_layer)
		return ;
	new_bot_layer->value = value;
	if (bot_layer)
	{
		bot_layer->next = new_bot_layer;
		new_bot_layer->prev = bot_layer;
	}
	else
		bot_layer = new_bot_layer;
}
