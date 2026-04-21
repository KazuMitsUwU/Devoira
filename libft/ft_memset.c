/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:59:28 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 13:49:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  *fills string with whatever you want as long as you want* */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_s;

	p_s = s;
	while (n--)
	{
		*p_s = (unsigned char)c;
		p_s++;
	}
	return (s);
}
