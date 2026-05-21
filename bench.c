/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 07:09:39 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/21 04:39:28 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_op(char *op)
{
	ft_printf("%s\n", op);
}

void	print_bench(t_bench *bench, int flag)
{
	ft_printf_fd(2, "[bench] disorder:    %.2f%%\n", bench->disorder * 100.0f);
	if (flag == FLAG_ADAPTIVE)
		ft_printf_fd(2, "[bench] strategy:    Adaptive sort \n");
	else if (flag == FLAG_SIMPLE)
		ft_printf_fd(2, "[bench] strategy:    Simple  O(n²)\n");
	else if (flag == FLAG_MEDIUM)
		ft_printf_fd(2, "[bench] strategy:    Medium  O(n√n)\n");
	else if (flag == FLAG_COMPLEX)
		ft_printf_fd(2, "[bench] strategy:    Complex  O(n log n)");
	ft_printf_fd(2, "[bench] total_ops:   %d\n", bench->total);
	ft_printf_fd(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf_fd(2, "[bench] ra: %d  rb: %d  rr: %d\n",
		bench->ra, bench->rb, bench->rr);
	ft_printf_fd(2, "[bench] rra: %d  rrb: %d  rrr: %d\n",
		bench->rra, bench->rrb, bench->rrr);
}
