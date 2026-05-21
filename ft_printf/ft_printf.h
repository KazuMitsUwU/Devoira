/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:21:35 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/18 19:50:17 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL_MESSAGE "(null)"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_float
{
	long	whole;
	long	frac;
	double	multiplier;
	int		precision;
}	t_float;

void	ft_putchar(char c, int fd, int *counter);
void	print_str(const char *str, int fd, int *counter);
void	print_hex(uintptr_t number, char delimiter, int fd, int *counter);
void	ft_putnbr(int number, int fd, int *counter);
void	print_memory(void *add, int fd, int *counter);
void	print_unsigned(unsigned int number, int fd, int *counter);
void	print_frac(long frac, int precision, int fd, int *cnt);
double	get_multiplier(int precision);
void	print_float_parts(t_float *f, int fd, int *cnt);
void	print_float(double n, int precision, int fd, int *cnt);
void	print_arg(char c, va_list *arg, int fd, int *counter);
void	handle_format(const char *str, int *index, va_list *arg, int *out);
int		ft_printf_core(int fd, const char *str, va_list *arg);
int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);

#endif
