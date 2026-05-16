/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_make_clean_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/15 17:18:05 by sitrakaa         ###   ########.fr       */
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

void	free_clean_arg_list(char **list)
{
	int	i;

	i = 0;
	if (!list[i])
		return ;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static void	split_and_fill(char **list, int *clean_i, char *string)
{
	char	**split;
	int		i;

	split = ft_split(string, ' ');
	if (!split || !split[0])
		error_exit(list, 3);
	i = 0;
	while (split[i])
	{
		list[*clean_i] = split[i];
		(*clean_i)++;
		i++;
	}
	free(split);
}

char	**make_clean_arg_list(int argc, char **argv)
{
	char	**list;
	int		clean_i;
	int		i;

	list = malloc(sizeof(char *) * (safe_space(argc, argv) + 1));
	if (!list)
		error_exit(NULL, 3);
	clean_i = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit(list, 3);
		if (ft_strchr(argv[i], ' '))
			split_and_fill(list, &clean_i, argv[i]);
		else
			list[clean_i++] = ft_strdup(argv[i]);
		i++;
	}
	list[clean_i] = NULL;
	return (list);
}
