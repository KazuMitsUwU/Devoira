/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoaran <manoaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:37:40 by manoaran          #+#    #+#             */
/*   Updated: 2026/02/10 13:14:07 by manoaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	=> allocates the memory needed for nmemb and filling it with 0 using bzero ;
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc_p;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	calloc_p = malloc(nmemb * size);
	if (!calloc_p)
		return (NULL);
	ft_bzero(calloc_p, nmemb * size);
	return (calloc_p);
}
