/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:24:20 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/07 09:53:00 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_init(t_stack **stack_a, int argc, char **argv)
{
	int	i;

	if (!argv[1])
		return ;
	i = 1;
	while (i < argc)
	{
		add_at_bot(stack_a, ft_atoi(argv[i]));
		i++;
	}
}

