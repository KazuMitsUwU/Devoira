/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:01:57 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/13 19:02:47 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int	argc, char	**argv, t_stack **stack_a, t_flags *flags)
{
	char	**clean_arg_list;
	int		new_argc;
	int		start;
	int		i;

	clean_arg_list = make_clean_arg_list(argc, argv);
	new_argc = define_new_argc(clean_arg_list);
	check_flags(new_argc, clean_arg_list, flags);
	start = flags->start;
	check_int_list(clean_arg_list, start);
	i = start;
	if (!clean_arg_list[i])
		return ;
	while (clean_arg_list[i])
	{
		add_at_bot(stack_a, my_atoi(clean_arg_list[i]));
		i++;
	}
}
