#include "push_swap.h"

int	disorder_metric(t_stack **stack_a)
{
	t_stack	*layer;
	int		disorder;

	disorder = 0;
	layer = *stack_a;
	while (layer->next)
	{
		if (layer->value > layer->next->value)
			disorder++;
		layer = layer->next;
	}
	return (disorder);
}