/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:52:35 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/17 16:12:06 by sitrakaa         ###   ########.fr       */
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

static void	handle_format(const char *str, int *index, va_list *arg,
				int fd, int *counter)
{
	int	precision;

	(*index)++;
	if (str[*index] == '.' || (str[*index] >= '0' && str[*index] <= '9'))
	{
		precision = 6;
		if (str[*index] == '.')
			(*index)++;
		if (str[*index] >= '0' && str[*index] <= '9')
		{
			precision = 0;
			while (str[*index] >= '0' && str[*index] <= '9')
				precision = precision * 10 + (str[(*index)++] - '0');
		}
		if (str[*index] == 'f')
			print_float(va_arg(*arg, double), precision, fd, counter);
		(*index)++;
	}
	else if (str[*index] == 'f')
	{
		print_float(va_arg(*arg, double), 6, fd, counter);
		(*index)++;
	}
	else
	{
		print_arg(str[*index], arg, fd, counter);
		(*index)++;
	}
}

int	ft_printf_core(int fd, const char *str, va_list *arg)
{
	int		index;
	int		counter;

	index = 0;
	counter = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == '%')
			handle_format(str, &index, arg, fd, &counter);
		else
			ft_putchar(str[index++], fd, &counter);
	}
	return (counter);
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
