/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:57:09 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/18 19:00:48 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_bench_flag(t_flags *flags, int *counts, char **list)
{
	counts[1]++;
	if (counts[1] > 1)
		error_exit(list, "Error: more than 1 bench flag found\n");
	flags->bench = 1;
}

static void	handle_strat_flag(char *arg, t_flags *flags, int *counts,
								char **list)
{
	int	flag_num;

	flag_num = is_valid_flag(arg);
	if (flag_num == -1)
		error_exit(list, "Error: invalid flag\n");
	counts[0]++;
	if (counts[0] > 1)
		error_exit(list, "Error: more than 1 strategy flag found\n");
	flags->strategy = flag_num;
}

void	find_flag(char *arg, t_flags *flags, int *counts, char **list)
{
	if (ft_strcmp(arg, "--bench") == 0)
		handle_bench_flag(flags, counts, list);
	else
		handle_strat_flag(arg, flags, counts, list);
}
