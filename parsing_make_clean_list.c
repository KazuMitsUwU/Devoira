/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_make_clean_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/14 06:14:41 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_space(int argc, char **argv)
{
	int	max_n_string;
	int	i;

	max_n_string = 0;
	i = 1;
	while (i < argc)
	{
		max_n_string += ft_strlen(argv[i]);
		i++;
	}
	return (max_n_string);
}

static void	split_and_fill(char **clean_arg_list, int *clean_arg_i,
							char *string)
{
	char	**split;
	int		i;

	split = ft_split(string, ' ');
	i = 0;
	while (split[i])
	{
		clean_arg_list[*clean_arg_i] = split[i];
		(*clean_arg_i)++;
		i++;
	}
	free(split);
}

char	**make_clean_arg_list(int argc, char **argv)
{
	char	**clean_arg_list;
	int		clean_i;
	int		i;

	clean_arg_list = malloc(sizeof(char *) * (safe_space(argc, argv) + 1));
	if (!clean_arg_list)
		return (NULL);
	clean_i = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			split_and_fill(clean_arg_list, &clean_i, argv[i]);
		else
			clean_arg_list[clean_i++] = argv[i];
		i++;
	}
	clean_arg_list[clean_i] = NULL;
	return (clean_arg_list);
}

void	check_int_list(char **clean_arg_list, int start)
{
	int		i;
	int		j;
	long	val_i;
	int		k;

	i = start;
	while (clean_arg_list[i])
	{
		if (!is_valid_int_str(clean_arg_list[i]))
			error_exit(3);
		val_i = 0;
		k = (clean_arg_list[i][0] == '-' || clean_arg_list[i][0] == '+') ? 1 : 0;
		while (clean_arg_list[i][k])
			val_i = val_i * 10 + (clean_arg_list[i][k++] - '0');
		if (clean_arg_list[i][0] == '-')
			val_i = -val_i;
		if (val_i < -2147483648L || val_i > 2147483647L)
			error_exit(3);
		j = i + 1;
		while (clean_arg_list[j])
		{
			if (ft_strcmp(clean_arg_list[i], clean_arg_list[j]) == 0)
				error_exit(4);
			j++;
		}
		i++;
	}
}
