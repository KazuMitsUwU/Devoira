/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:38:57 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 10:10:55 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* concatenates until size reached */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	dst_i;
	size_t	src_i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	dst_i = dst_len;
	src_i = 0;
	while (dst_i < (size - 1) && src[src_i])
		dst[dst_i++] = src[src_i++];
	dst[dst_i] = '\0';
	return (dst_len + src_len);
}
