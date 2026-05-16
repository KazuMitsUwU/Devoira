/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:22:04 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/04/10 15:33:42 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(uintptr_t n, char base, int fd, int *cnt)
{
	uintptr_t	d;

	if (n >= 16)
		print_hex(n / 16, base, fd, cnt);
	d = n % 16;
	if (d < 10)
		d += '0';
	else
		d += base - 10;
	ft_putchar(d, fd, cnt);
}

void	print_unsigned(unsigned int n, int fd, int *cnt)
{
	if (n >= 10)
		print_unsigned(n / 10, fd, cnt);
	ft_putchar((n % 10) + '0', fd, cnt);
}

void	print_memory(void *ptr, int fd, int *cnt)
{
	if (ptr == NULL)
	{
		print_str("(nil)", fd, cnt);
		return ;
	}
	print_str("0x", fd, cnt);
	print_hex((uintptr_t)ptr, 'a', fd, cnt);
}
