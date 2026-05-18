/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:55:51 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/18 22:58:28 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int	find_min(t_stack **a)
{
	t_stack	*cur;
	int		min;

	cur = *a;
	min = cur->value;
	while (cur)
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	return (min);
}

void	push_two_min(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	pushed;

	pushed = 0;
	i = 0;
	while (pushed < 2)
	{
		if ((*a)->value == find_min(a))
		{
			pb(a, b, bench);
			pushed++;
		}
		else
			ra(a, bench);
	}
}
