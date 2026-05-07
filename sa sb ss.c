/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa sb ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:17:59 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/07 09:51:22 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_combine *c)
{
	int		temp;
	t_stack	*top_layer;

	top_layer = *c->stack_a;
	if (!c->stack_a || !top_layer || !top_layer->next)
		return ;
	temp = top_layer->value;
	top_layer->value = top_layer->next->value;
	top_layer->next->value = temp;
	c->bench->sa++;
}

void	sb(t_combine *c)
{
	t_combine	swapped;

	swapped.stack_a = c->stack_b;
	swapped.stack_b = c->stack_a;
	swapped.bench = c->bench;
	sa(&swapped);
	c->bench->sa--;
	c->bench->sb++;
}

void	ss(t_combine *c)
{
	sa(c);
	sb(c);
	c->bench->sa--;
	c->bench->sb--;
	c->bench->ss++;
}
