/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:00:57 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 13:51:13 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* "fd is for File Descriptor and indicates where the output is going to be,
	using 0/1/2,..., can't be negative"*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
