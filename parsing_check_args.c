/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 06:43:58 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/18 19:02:53 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flags(int clean_argc, char **list, t_flags *flags)
{
	int	i;
	int	counts[2];

	flags->strategy = FLAG_ADAPTIVE;
	flags->bench = 0;
	flags->start = 0;
	counts[0] = 0;
	counts[1] = 0;
	i = 0;
	while (i < clean_argc)
	{
		if (list[i][0] == '-' && list[i][1] == '-')
		{
			find_flag(list[i], flags, counts, list);
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
			error_exit(list, "Error: misplaced flag\n");
		if (str[1] == '\0')
			error_exit(list, "Error: invalid integer found\n");
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit(list, "Error: invalid integer found\n");
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
			error_exit(list, "Error: integer duplicate found\n");
		i++;
	}
}
