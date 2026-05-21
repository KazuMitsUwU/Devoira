/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:52:47 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/19 16:40:09 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bench	init_bench(void)
{
	t_bench	bench;

	bench.disorder = 0.0f;
	bench.sa = 0;
	bench.sb = 0;
	bench.ss = 0;
	bench.pa = 0;
	bench.pb = 0;
	bench.ra = 0;
	bench.rb = 0;
	bench.rr = 0;
	bench.rra = 0;
	bench.rrb = 0;
	bench.rrr = 0;
	bench.total = 0;
	return (bench);
}

static void	run_strategy(t_stack **a, t_stack **b,
							t_flags *flags, t_bench *bench)
{
	bench->disorder = disorder_metric(a);
	if (flags->strategy == FLAG_SIMPLE)
		insertion_sort(a, b, bench);
	else if (flags->strategy == FLAG_MEDIUM)
		chunk_sort(a, b, bench);
	else if (flags->strategy == FLAG_COMPLEX)
		radix_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	flags;
	t_bench	bench;

	stack_a = NULL;
	stack_b = NULL;
	bench = init_bench();
	parsing(argc, argv, &stack_a, &flags);
	if (!stack_a)
		return (0);
	check_if_sorted(&stack_a);
	run_strategy(&stack_a, &stack_b, &flags, &bench);
	if (flags.bench)
		print_bench(&bench, flags.strategy);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
