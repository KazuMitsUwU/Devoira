/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:32:08 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/18 17:36:56 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_flag(char *flag)
{
	if (ft_strncmp(flag, "--simple", 8) == 0)
		return (FLAG_SIMPLE);
	if (ft_strncmp(flag, "--medium", 8) == 0)
		return (FLAG_MEDIUM);
	if (ft_strncmp(flag, "--complex", 9) == 0)
		return (FLAG_COMPLEX);
	if (ft_strncmp(flag, "--adaptive", 10) == 0)
		return (FLAG_ADAPTIVE);
	return (-1);
}

int	define_clean_argc(char **clean_arg_list)
{
	int	n;

	if (!clean_arg_list)
		return (0);
	n = 0;
	while (clean_arg_list[n])
		n++;
	return (n);
}

static void	sign_check(char c, int *sign, long *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign = -1;
		(*i)++;
	}
}

int	my_atoi(const char *arg, char **list)
{
	long	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	sign_check(arg[i], &sign, &i);
	result = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			error_exit(list, "Error: invalid integer found\n");
		result = (result * 10) + (arg[i] - '0');
		if (result * sign < -2147483648 || result * sign > 2147483647)
			error_exit(list, "Error: invalid integer found\n");
		i++;
	}
	result *= sign;
	return ((int)result);
}

void	split_and_fill(char **list, int *clean_i, char *string)
{
	char	**split;
	int		i;

	split = ft_split(string, ' ');
	if (!split || !split[0])
	{
		if (split)
			free(split);
		return ;
	}
	i = 0;
	while (split[i])
	{
		list[*clean_i] = split[i];
		(*clean_i)++;
		i++;
	}
	free(split);
}
