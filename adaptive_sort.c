/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:01 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 21:48:54 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	float	disorder;

	disorder = disorder_metric(a);
	if (disorder == 0.0f)
		return ;
	else if (disorder < 0.1f)
		insertion_sort(a, b, bench);
	else if (disorder < 0.5f)
		chunk_sort(a, b, bench);
	else
		radix_sort(a, b, bench);
}
