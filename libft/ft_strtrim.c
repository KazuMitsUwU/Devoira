/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:51:19 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 15:34:44 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	=> move index forward as long as the current char belongs to the set,
		in order to have the starting index of the trimmed string;
		
	=> allocates one byte for the null in case all of the char are part of set;
	
	=> same opertion as the first but looking backwards to find the last index
		with chars part of set removed;
	
	=> calculates the length of the trimmed string and sends the values to 
		substr for memory allocation of the string, and returns it; 
*/

#include "libft.h"

static char	*full_trim(void)
{
	char	*empty;

	empty = malloc(1);
	if (!empty)
		return (NULL);
	*empty = '\0';
	return (empty);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i_end;
	char	*final_s;
	size_t	final_len;

	if (!s1 || !set)
		return (NULL);
	i_start = 0;
	while (ft_strchr(set, s1[i_start]))
		i_start++;
	if (s1[i_start] == '\0')
		return (full_trim());
	i_end = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[i_end]))
		i_end--;
	final_len = i_end - i_start + 1;
	final_s = ft_substr(s1, (unsigned int)i_start, final_len);
	return (final_s);
}
