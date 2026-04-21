/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:20:05 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 15:01:44 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	measures, allocates, fill with characters after application of f */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result_box;
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	result_box = malloc(s_len + 1);
	if (!result_box)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result_box[i] = f((unsigned int)i, s[i]);
		i++;
	}
	result_box[i] = '\0';
	return (result_box);
}
