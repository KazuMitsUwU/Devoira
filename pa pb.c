/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:12:36 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/07 09:43:16 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_combine *c)
{
	int		value;
	t_stack	*top_layer_b;

	if (!c->stack_b || !*c->stack_b)
		return ;
	top_layer_b = *c->stack_b;
	value = top_layer_b->value;
	add_on_top(c->stack_a, value);
	if (top_layer_b->next)
	{
		top_layer_b = top_layer_b->next;
		free(top_layer_b->prev);
		top_layer_b->prev = NULL;
		*c->stack_b = top_layer_b;
	}
	else
	{
		free(top_layer_b);
		*c->stack_b = NULL;
	}
	c->bench->pa++;
}

void	pb(t_combine *c)
{
	t_combine	swapped;

	swapped.stack_a = c->stack_b;
	swapped.stack_b = c->stack_a;
	swapped.bench = c->bench;
	pa(&swapped);
	c->bench->pa--;
	c->bench->pb++;
}
