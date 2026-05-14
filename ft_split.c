/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:35:38 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/13 21:37:23 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	*split_str(char const **s, char c)
{
	char const	*start;
	char		*word;
	size_t		len;

	while (**s == c && **s)
		(*s)++;
	start = *s;
	while (**s != c && **s)
		(*s)++;
	len = *s - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	take_out(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**final_arr;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	final_arr = malloc((count + 1) * sizeof(char *));
	if (!final_arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		final_arr[i] = split_str(&s, c);
		if (!final_arr[i])
		{
			take_out(final_arr, i);
			return (NULL);
		}
		i++;
	}
	final_arr[i] = NULL;
	return (final_arr);
}
