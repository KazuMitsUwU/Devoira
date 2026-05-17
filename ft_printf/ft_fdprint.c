/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:07:15 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/17 16:08:32 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, str);
	ret = ft_printf_core(fd, str, &arg);
	va_end(arg);
	return (ret);
}
