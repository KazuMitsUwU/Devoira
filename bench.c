#include "push_swap.h"

void	print_ops(t_bench *bench)
{
	ft_printf("Operations:\n");
	ft_printf("  sa : %d\n", bench->sa);
	ft_printf("  sb : %d\n", bench->sb);
	ft_printf("  ss : %d\n", bench->ss);
	ft_printf("  pa : %d\n", bench->pa);
	ft_printf("  pb : %d\n", bench->pb);
	ft_printf("  ra : %d\n", bench->ra);
	ft_printf("  rb : %d\n", bench->rb);
	ft_printf("  rr : %d\n", bench->rr);
	ft_printf("  rra: %d\n", bench->rra);
	ft_printf("  rrb: %d\n", bench->rrb);
	ft_printf("  rrr: %d\n", bench->rrr);
	ft_printf("  total: %d\n", bench->total);
}

void	print_disorder(t_bench *bench)
{
	ft_printf("Disorder: %.2f%%\n", bench->disorder);
}

void	print_flag(int flag)
{
	ft_printf("Algorithm: ");
	if (flag == 0)
		ft_printf("simple\n");
	else if (flag == 1)
		ft_printf("adaptive\n");
	else if (flag == 2)
		ft_printf("chunk\n");
	else if (flag == 3)
		ft_printf("radix\n");
}

void	print_bench(t_bench *bench, int flag)
{
	print_disorder(bench);
	print_flag(flag);
	print_ops(bench);
}
