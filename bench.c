/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 07:09:39 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/14 00:00:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

void	print_bench(t_bench *bench, int flag)
{
	dprintf(2, "[bench] disorder:    %.2f%%\n", bench->disorder * 100.0f);
	if (flag == FLAG_ADAPTIVE)
		dprintf(2, "[bench] strategy:    Adaptive\n");
	else if (flag == FLAG_SIMPLE)
		dprintf(2, "[bench] strategy:    Simple (insertion)\n");
	else if (flag == FLAG_MEDIUM)
		dprintf(2, "[bench] strategy:    Chunk\n");
	else if (flag == FLAG_COMPLEX)
		dprintf(2, "[bench] strategy:    Radix\n");
	dprintf(2, "[bench] total_ops:   %d\n", bench->total);
	dprintf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	dprintf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
