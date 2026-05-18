/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_make_clean_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/18 18:56:25 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blank(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

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
	{
		free(list);
		return ;
	}
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	make_clean_loop(int argc, char **argv, char ***list)
{
	int	i;
	int	clean_i;

	clean_i = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_blank(argv[i]))
		{
			i++;
			continue ;
		}
		if (ft_strchr(argv[i], ' '))
			split_and_fill(*list, &clean_i, argv[i]);
		else
			(*list)[clean_i++] = ft_strdup(argv[i]);
		i++;
	}
	(*list)[clean_i] = NULL;
}

char	**make_clean_arg_list(int argc, char **argv)
{
	char	**list;

	if (argc < 2)
		exit(0);
	list = malloc(sizeof(char *) * (safe_space(argc, argv) + 1));
	if (!list)
		error_exit(NULL, "Error: malloc failed\n");
	make_clean_loop(argc, argv, &list);
	if (!list[0])
	{
		free(list);
		exit(0);
	}
	return (list);
}
