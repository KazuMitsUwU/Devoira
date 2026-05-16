/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:22:04 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/14 20:15:26 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(uintptr_t n, char base, int *cnt)
{
	uintptr_t	d;

	if (n >= 16)
		print_hex(n / 16, base, cnt);
	d = n % 16;
	if (d < 10)
		d += '0';
	else
		d += base - 10;
	ft_charput(d, cnt);
}

void	print_unsigned(unsigned int n, int *cnt)
{
	if (n >= 10)
		print_unsigned(n / 10, cnt);
	ft_charput((n % 10) + '0', cnt);
}

void	print_memory(void *ptr, int *cnt)
{
	if (ptr == NULL)
	{
		str_print("(nil)", cnt);
		return ;
	}
	str_print("0x", cnt);
	print_hex((uintptr_t)ptr, 'a', cnt);
}
