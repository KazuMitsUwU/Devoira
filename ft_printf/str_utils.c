/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:22:11 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/14 21:42:50 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int fd, int *cnt)
{
	*cnt += write(fd, &c, 1);
}

void	print_str(const char *s, int fd, int *cnt)
{
	int	i;

	if (s == NULL)
	{
		print_str(NULL_MESSAGE, fd, cnt);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd, cnt);
		i++;
	}
}
