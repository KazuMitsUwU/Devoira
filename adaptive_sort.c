/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:01 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/18 23:55:55 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_stack **a, t_stack **b, t_bench *bench, int nb)
{
	if (nb <= 3)
		three_five_sort(a, b, bench);
	else
		three_five_sort(a, b, bench);
}

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		nb;
	float	disorder;

	nb = stack_size(*a);
	if (nb <= 5)
		return (small_sort(a, b, bench, nb));
	disorder = disorder_metric(a);
	if (nb >= 100 || disorder >= 0.5f)
		radix_sort(a, b, bench);
	else if (disorder == 0.0f)
		return ;
	else if (disorder < 0.1f)
		insertion_sort(a, b, bench);
	else
		chunk_sort(a, b, bench);
}
