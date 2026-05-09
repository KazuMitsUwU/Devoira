/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/07 09:56:28 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *str)
{
	return (ft_strncmp(str, "--simple", 8) == 0
		|| ft_strncmp(str, "--medium", 8) == 0
		|| ft_strncmp(str, "--complex", 9) == 0
		|| ft_strncmp(str, "--adaptive", 10) == 0
		|| ft_strncmp(str, "--bench", 7) == 0);
}

static void	split_and_fill(char **rework, int *arg_i, char *str)
{
	char	**split;
	int		j;

	split = ft_split(str, ' ');
	j = 0;
	while (split[j])
	{
		rework[*arg_i] = split[j];
		(*arg_i)++;
		j++;
	}
	free(split);
}

static int	define_worst_case(int argc, char **argv)
{
	int	max;
	int	i;

	max = 0;
	i = 1;
	while (i < argc)
	{
		max += ft_strlen(argv[i]);
		i++;
	}
	return (max);
}

char	**build_rework(int argc, char **argv)
{
	char	**rework;
	int		arg_i;
	int		i;

	rework = malloc(sizeof(char *) * (define_worst_case(argc, argv) + 1));
	if (!rework)
		return (NULL);
	arg_i = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			{ i++; continue ; }
		if (ft_strchr(argv[i], ' '))
			split_and_fill(rework, &arg_i, argv[i]);
		else
			rework[arg_i++] = argv[i];
		i++;
	}
	rework[arg_i] = NULL;
	return (rework);
}

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