/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:59:25 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 07:40:41 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> casts s to unsigned char to operate byte by byte
	 	and filling each one with 0 for n size;
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_s;

	p_s = s;
	while (n > 0)
	{
		*p_s = 0;
		p_s++;
		n--;
	}
}
