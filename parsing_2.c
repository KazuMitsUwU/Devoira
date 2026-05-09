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

int	get_strategies(int argc, char **argv, int *strategies)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			strategies[count++] = 0;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			strategies[count++] = 1;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			strategies[count++] = 2;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			strategies[count++] = 3;
		i++;
	}
	if (count == 0)
		strategies[count++] = 3;
	return (count);
}

int	get_bench(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	stack_a_init(t_stack **stack_a, char **rework)
{
	int	i;

	if (!rework || !rework[0])
		return ;
	i = 0;
	while (rework[i])
	{
		add_at_bot(stack_a, ft_atoi(rework[i]));
		i++;
	}
}