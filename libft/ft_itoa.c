/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:12:07 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 13:39:30 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> "measures" n for malloc and making sure it works for both negative or 0;
	
	=> allocates mem for the string to be returned and simply storing 0 for n=0;

	=> makes a type long copy of n to manipulate value of n safely;
	
	=> if the number is negative, turns it to positive and immediately assign
		'-' to the first index of the string;
	
	=> converts the number and fills the string digit per digit in reverse order;
*/

#include "libft.h"

static size_t	n_len(long n)
{
	size_t	n_char;

	n_char = 0;
	if (n <= 0)
		n_char = 1;
	while (n != 0)
	{
		n_char++;
		n /= 10;
	}
	return (n_char);
}

static void	convert(char *string, size_t n_char, long n_dup)
{
	size_t	i;

	i = n_char - 1;
	while (n_dup > 0)
	{
		string[i] = (n_dup % 10) + '0';
		n_dup /= 10;
		i--;
	}
	string[n_char] = '\0';
}

char	*ft_itoa(int n)
{
	char	*the_string;
	long	n_cpy;
	size_t	n_char;

	n_char = n_len(n);
	the_string = malloc(n_char + 1);
	if (!the_string)
		return (NULL);
	if (n == 0)
		the_string[0] = '0';
	n_cpy = n;
	if (n_cpy < 0)
	{
		n_cpy *= -1;
		the_string[0] = '-';
	}
	convert(the_string, n_char, n_cpy);
	return (the_string);
}
