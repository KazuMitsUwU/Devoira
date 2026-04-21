/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:55:10 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 16:43:52 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> same as strcpy but operates byte by byte...;
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return ((void *)p_dest);
}
