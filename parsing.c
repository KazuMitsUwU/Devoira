/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/04/28 11:00:11 by manoaran         ###   ########.fr       */
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
		add_on_top(stack_a, ft_atoi(argv[i]));
		i++;
	}
}
