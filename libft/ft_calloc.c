/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:02:08 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/19 09:18:17 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		pointer = malloc(0);
		return (pointer);
	}
	if (((nmemb * size) / size) != nmemb)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}
