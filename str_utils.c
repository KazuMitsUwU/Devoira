/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:22:11 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/15 07:27:39 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	ft_putchar(char c, int fd, int *cnt)
{
	*cnt += write(fd, &c, 1);
}

void	print_str(const char *s, int fd, int *cnt)
{
	int	i;

	if (s == NULL)
	{
		print_str(NULL_MESSAGE, fd, cnt);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd, cnt);
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
