/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 00:00:00 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/15 07:19:04 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char **list, int error_type)
{
	if (list)
		free_clean_arg_list(list);
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
	exit(1);
}
