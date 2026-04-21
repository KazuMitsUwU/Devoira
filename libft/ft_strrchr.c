/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:19:26 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 15:15:00 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* same as strrchr but starts from right to left */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p_s;
	size_t		rev_count;

	p_s = s;
	rev_count = ft_strlen(s);
	while (rev_count--)
	{
		if (p_s[rev_count] == (unsigned char)c)
			return ((char *)&p_s[rev_count]);
	}
	if ((unsigned char)c == '\0')
		return ((char *)&p_s[ft_strlen(s)]);
	return (NULL);
}
