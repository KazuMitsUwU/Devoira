/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:21:35 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/15 06:40:06 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL_MESSAGE "(null)"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

void	ft_putchar(char c, int fd, int *counter);
void	print_str(const char *str, int fd, int *counter);
void	print_hex(uintptr_t number, char delimiter, int fd, int *counter);
void	ft_putnbr(int number, int fd, int *counter);
void	print_memory(void *add, int fd, int *counter);
void	print_unsigned(unsigned int number, int fd, int *counter);
void	print_arg(char c, va_list *arg, int fd, int *counter);

int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);

#endif
