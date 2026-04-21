/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:08:00 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 14:17:57 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* *finds character and returns address or null* */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p_s;
	size_t		i;

	p_s = s;
	i = 0;
	while (p_s[i])
	{
		if (p_s[i] == (unsigned char)c)
			return ((char *)p_s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)p_s + i);
	return (NULL);
}
