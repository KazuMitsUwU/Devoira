/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra rb rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:15:50 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/07 09:50:48 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_combine *c)
{
	int		value;
	t_stack	*top_layer;
	t_stack	*old_top;

	top_layer = *c->stack_a;
	if (!top_layer || !top_layer->next)
		return ;
	value = top_layer->value;
	add_at_bot(c->stack_a, value);
	top_layer = top_layer->next;
	old_top = top_layer->prev;
	*c->stack_a = top_layer;
	top_layer->prev = NULL;
	free(old_top);
	c->bench->ra++;
}

void	rb(t_combine *c)
{
	t_combine	swapped;

	swapped.stack_a = c->stack_b;
	swapped.stack_b = c->stack_a;
	swapped.bench = c->bench;
	ra(&swapped);
	c->bench->ra--;
	c->bench->rb++;
}

void	rr(t_combine *c)
{
	ra(c);
	rb(c);
	c->bench->ra--;
	c->bench->rb--;
	c->bench->rr++;
}
