/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:09:00 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/18 19:49:33 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_precision(const char *str, int *index, va_list *arg,
								int *out)
{
	int	precision;

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
		print_float(va_arg(*arg, double), precision, out[0], &out[1]);
	(*index)++;
}

void	handle_format(const char *str, int *index, va_list *arg, int *out)
{
	(*index)++;
	if (str[*index] == '.' || (str[*index] >= '0' && str[*index] <= '9'))
		handle_precision(str, index, arg, out);
	else if (str[*index] == 'f')
	{
		print_float(va_arg(*arg, double), 6, out[0], &out[1]);
		(*index)++;
	}
	else
	{
		print_arg(str[*index], arg, out[0], &out[1]);
		(*index)++;
	}
}
