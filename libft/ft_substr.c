/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:11:30 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 08:43:18 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> makes sure start index is within scope of s;
	=> reduces len of the substring if it goes out of scope;
	=> allocates mem for the substring;
	=> fills the allocated mem with the substring within s;
	=> returns the substring in its own mem area;
*/

#include "libft.h"

static char	*null_byte(void)
{
	char	*empty;

	empty = malloc(1);
	if (!empty)
		return (NULL);
	*empty = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p_sub;
	size_t	i_start;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
	i_start = (size_t)start;
	len_s = ft_strlen(s);
	if (i_start >= len_s)
		return (null_byte());
	if (len > (len_s - i_start))
		len = len_s - i_start;
	p_sub = malloc(len + 1);
	if (!p_sub)
		return (NULL);
	i = 0;
	while (i < len)
		*(p_sub + i++) = s[i_start++];
	*(p_sub + i) = '\0';
	return (p_sub);
}
