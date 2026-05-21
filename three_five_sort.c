/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:55:51 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/21 04:27:37 by sitrakaa         ###   ########.fr       */
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

static int	find_min(t_stack **a)
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

static void	push_two_min(t_stack **a, t_stack **b, t_bench *bench)
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

void	three_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	(void)b;
	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top < bot)
		sa(a, bench);
	else if (top > bot && mid > bot)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (mid > bot && top < bot)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (top > mid && top > bot)
		ra(a, bench);
	else if (mid > top && mid > bot)
		rra(a, bench);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	push_two_min(a, b, bench);
	three_sort(a, b, bench);
	if ((*b)->next && (*b)->next->value > (*b)->value)
		sb(b, bench);
	pa(a, b, bench);
	pa(a, b, bench);
}
