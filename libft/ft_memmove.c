/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:10:15 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 16:44:23 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> move an area of the memory to another using memcpy;

	=> copies content in reverse if areas are mixed to avoid overlap;
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (p_dest < p_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			p_dest[n] = p_src[n];
	}
	return (p_dest);
}
