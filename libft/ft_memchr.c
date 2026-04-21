/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:36:38 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 13:41:45 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> same behavior as strchr except it operates byte by byte,
		which is why we use unsigned int ;
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p_s;
	size_t				i;

	p_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)(p_s + i));
		i++;
	}
	return (NULL);
}
