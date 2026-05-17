/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:49:17 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/17 15:50:17 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_frac(long frac, int precision, int fd, int *cnt)
{
	char	buf[20];
	int		i;

	i = precision - 1;
	while (i >= 0)
	{
		buf[i] = (frac % 10) + '0';
		frac /= 10;
		i--;
	}
	buf[precision] = '\0';
	print_str(buf, fd, cnt);
}

double	get_multiplier(int precision)
{
	double	multiplier;
	int		i;

	multiplier = 1.0;
	i = 0;
	while (i < precision)
	{
		multiplier *= 10.0;
		i++;
	}
	return (multiplier);
}

void	print_float_parts(t_float *f, int fd, int *cnt)
{
	if (f->frac >= (long)f->multiplier)
	{
		f->whole++;
		f->frac = 0;
	}
	ft_putnbr((int)f->whole, fd, cnt);
	ft_putchar('.', fd, cnt);
	print_frac(f->frac, f->precision, fd, cnt);
}

void	print_float(double n, int precision, int fd, int *cnt)
{
	t_float	f;

	if (n < 0)
	{
		ft_putchar('-', fd, cnt);
		n = -n;
	}
	f.multiplier = get_multiplier(precision);
	f.precision = precision;
	f.whole = (long)n;
	f.frac = (long)((n - (double)f.whole) * f.multiplier + 0.5);
	print_float_parts(&f, fd, cnt);
}
