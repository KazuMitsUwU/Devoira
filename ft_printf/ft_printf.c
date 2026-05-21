/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:52:35 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/18 19:57:35 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char c, va_list *arg, int fd, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(*arg, int), fd, counter);
	else if (c == 's')
		print_str(va_arg(*arg, char *), fd, counter);
	else if (c == 'p')
		print_memory(va_arg(*arg, void *), fd, counter);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*arg, int), fd, counter);
	else if (c == 'u')
		print_unsigned(va_arg(*arg, unsigned int), fd, counter);
	else if (c == 'x')
		print_hex(va_arg(*arg, unsigned int), 'a', fd, counter);
	else if (c == 'X')
		print_hex(va_arg(*arg, unsigned int), 'A', fd, counter);
	else if (c == '%')
		ft_putchar(c, fd, counter);
}

int	ft_printf_core(int fd, const char *str, va_list *arg)
{
	int		index;
	int		out[2];

	index = 0;
	out[0] = fd;
	out[1] = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == '%')
			handle_format(str, &index, arg, out);
		else
			ft_putchar(str[index++], out[0], &out[1]);
	}
	return (out[1]);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, str);
	ret = ft_printf_core(1, str, &arg);
	va_end(arg);
	return (ret);
}
