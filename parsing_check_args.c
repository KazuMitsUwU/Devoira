/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:00:00 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 06:14:35 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *arg)
{
	return (ft_strcmp(arg, "--bench") == 0
		|| ft_strcmp(arg, "-s") == 0
		|| ft_strcmp(arg, "-m") == 0
		|| ft_strcmp(arg, "-c") == 0
		|| ft_strcmp(arg, "-a") == 0);
}

void	check_flags(int new_argc, char **argv, t_flags *flags)
{
	int	i;
	int	bench_count;
	int	strategy_count;

	flags->strategy = FLAG_ADAPTIVE;
	flags->bench = 0;
	flags->start = 0;
	bench_count = 0;
	strategy_count = 0;
	i = 0;
	while (i < new_argc && is_flag(argv[i]))
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
		{
			bench_count++;
			if (bench_count > 1)
				error_exit(0);
			flags->bench = 1;
		}
		else
		{
			strategy_count++;
			if (strategy_count > 1)
				error_exit(1);
			if (ft_strcmp(argv[i], "-s") == 0)
				flags->strategy = FLAG_SIMPLE;
			else if (ft_strcmp(argv[i], "-m") == 0)
				flags->strategy = FLAG_MEDIUM;
			else if (ft_strcmp(argv[i], "-c") == 0)
				flags->strategy = FLAG_COMPLEX;
			else if (ft_strcmp(argv[i], "-a") == 0)
				flags->strategy = FLAG_ADAPTIVE;
			else
				error_exit(2);
		}
		i++;
	}
	flags->start = i;
	while (i < new_argc)
	{
		if (is_flag(argv[i]))
			error_exit(5);
		i++;
	}
}

static int	is_valid_int_str(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

