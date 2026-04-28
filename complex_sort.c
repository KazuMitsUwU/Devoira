/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:18:51 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/28 09:24:11 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* compte le nombre de colonnes binaires necessaires pour couvrir toutes les positions */
static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	/* la plus grande position possible c'est size - 1 */
	max = size - 1;
	bits = 0;
	/* on decale max vers la droite jusqu'a ce qu'il soit a 0 */
	/* chaque decalage = une colonne binaire de moins */
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_stack **stack_a, t_stack **stack_b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		/* si le bit courant est 1 on garde dans a, sinon on envoie dans b */
		if (((*stack_a)->position >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	/* on ramene tout dans a */
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		max_bits;
	int		bit;
	int		*temp_arr;

	size = nb_of_layer(stack_a);
	temp_arr = make_temp_arr(stack_a, size);
	sort_arr(temp_arr, size);
	define_positions(stack_a, temp_arr, size);
	free(temp_arr);
	max_bits = get_max_bits(size);
	bit = 0;
	/* une passe par colonne binaire */
	while (bit < max_bits)
	{
		radix_pass(stack_a, stack_b, bit, size);
		bit++;
	}
}