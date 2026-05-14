/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:32:08 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/13 15:43:09 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_new_argc(char **clean_arg_list)
{
	int	n;

	if (!clean_arg_list)
		return (0);
	n = 0;
	while (clean_arg_list[n])
		n++;
	return (n);
}

void	error_exit(int error_type)
{
	if (error_type == 0)
		write(2, "Error: more than 1 bench flag found\n", 36);
	if (error_type == 1)
		write(2, "Error: more than 1 strategy flag found\n", 39);
	if (error_type == 2)
		write(2, "Error: invalid flag\n", 20);
	if (error_type == 3)
		write(2, "Error: invalid integer found\n", 29);
	if (error_type == 4)
		write(2, "Error: integer duplicate found\n", 31);
	if (error_type == 5)
		write(2, "Error: misplaced flag\n", 22);
	else
		write(2, "Error\n", 6);
	exit(1);
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

int	my_atoi(const char *arg)
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
			error_exit(3);
		result = (result * 10) + (arg[i] - '0');
		i++;
	}
	result *= sign;
	if ((result < -2147483648) || (result > 2147483647))
		error_exit(3);
	return ((int)result);
}
