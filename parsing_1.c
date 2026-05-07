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

#include"push_swap.h"

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
		if (ft_strchr(argv[i], ' '))
			split_and_fill(rework, &arg_i, argv[i]);
		else
			rework[arg_i++] = argv[i];
		i++;
	}
	rework[arg_i] = NULL;
	return (rework);
}
