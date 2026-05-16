/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 06:43:58 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/15 07:30:22 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_flag(char *arg, t_flags *flags, int *n_strat,
						int *n_bench, char **list)
{
	int	flag_num;

	if (ft_strcmp(arg, "--bench") == 0)
	{
		(*n_bench)++;
		if (*n_bench > 1)
			error_exit(list, 0);
		flags->bench = 1;
	}
	else
	{
		flag_num = is_valid_flag(arg);
		if (flag_num == -1)
			error_exit(list, 2);
		(*n_strat)++;
		if (*n_strat > 1)
			error_exit(list, 1);
		flags->strategy = flag_num;
	}
}

void	check_flags(int clean_argc, char **list, t_flags *flags)
{
	int	i;
	int	n_strat;
	int	n_bench;

	flags->strategy = FLAG_ADAPTIVE;
	flags->bench = 0;
	flags->start = 0;
	n_strat = 0;
	n_bench = 0;
	i = 0;
	while (i < clean_argc)
	{
		if (list[i][0] == '-' && list[i][1] == '-')
		{
			find_flag(list[i], flags, &n_strat, &n_bench, list);
			flags->start++;
			i++;
		}
		else
			return ;
	}
}

static int	duplicate_found(char **list, char *value, int cur, int start)
{
	int	i;

	i = start;
	while (i < cur)
	{
		if (my_atoi(list[i], list) == my_atoi(value, list))
			return (1);
		i++;
	}
	return (0);
}

static void	check_if_int(char *str, char **list)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '-')
			error_exit(list, 5);
		if (str[1] == '\0')
			error_exit(list, 3);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit(list, 3);
		i++;
	}
}

void	check_int_list(char **list, int start)
{
	int	i;

	i = start;
	if (!list[i])
		return ;
	while (list[i])
	{
		check_if_int(list[i], list);
		if (duplicate_found(list, list[i], i, start))
			error_exit(list, 4);
		i++;
	}
}
