/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:21:46 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/10 15:33:37 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int number, int fd, int *counter)
{
	if (number == INT_MIN)
	{
		print_str("-2147483648", fd, counter);
		return ;
	}
	if (number < 0)
	{
		ft_putchar('-', fd, counter);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr(number / 10, fd, counter);
	ft_putchar((number % 10) + '0', fd, counter);
}
