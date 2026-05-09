#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	float	disorder;

	disorder = disorder_metric(a);
	if (disorder == 0.0f)
		return ;
	if (stack_size(a) <= 3)
		sort_small(a, bench);
	else if (disorder < 0.1f)
		insertion_sort(, bench);
	else if (disorder < 0.5f)
		chunk_sort(a, b, bench);
	else
		radix_sort(a, b, bench);
}