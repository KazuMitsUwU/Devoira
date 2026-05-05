/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/04 21:01:08 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strategy_selector(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] && arg[i][1] == '-')
		{
			if (ft_strcmp(argv[i], "--simple", 30) == 0)
			}
		}
}

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
