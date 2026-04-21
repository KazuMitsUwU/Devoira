/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:08:43 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 16:56:20 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> skips whitespaces (tabs, spaces, ...) ;
	
	=> make sign negative if minus char found before any digit is ;
	
	=> transforms number string into int, using * 10 to repetitively
		add room for a new digit until a non digit is found ;
	
	=> returns the result * sign to make it negative if minus was found, 
		otherwise positive by default ;
*/

#include "libft.h"

static void	sign_check(char c, int *sign, int *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		returned_value;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	sign_check(nptr[i], &sign, &i);
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	returned_value = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		returned_value = (returned_value * 10) + (nptr[i] - '0');
		i++;
	}
	return (returned_value * sign);
}
