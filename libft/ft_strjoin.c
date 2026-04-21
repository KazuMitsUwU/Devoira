/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:27:30 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/13 16:33:24 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* measures, allocates, combines, returns */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((len_s1 > (((size_t) - 1) - len_s2)) || (!s1 && !s2))
		return (NULL);
	new_s = malloc(len_s1 + len_s2 + 1);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, (len_s1 + 1));
	i = 0;
	while ((len_s1 + i) < (len_s1 + len_s2))
	{
		new_s[len_s1 + i] = s2[i];
		i++;
	}
	new_s[len_s1 + i] = '\0';
	return (new_s);
}
