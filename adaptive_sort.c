/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:01 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/21 04:44:21 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		nb;
	float	disorder;

	nb = stack_size(*a);
	if (nb == 3)
		return (three_sort(a, b, bench));
	else if (nb == 5)
		return (sort_five(a, b, bench));
	disorder = disorder_metric(a);
	if (disorder == 0.0f)
		return ;
	else if (nb <= 100 && disorder < 0.2f)
		return (insertion_sort(a, b, bench));
	else if (nb <= 100 && disorder < 0.5f)
		return (chunk_sort(a, b, bench));
	else if (nb <= 500 && disorder < 0.5f)
		return (chunk_sort(a, b, bench));
	else
		return (radix_sort(a, b, bench));
}
