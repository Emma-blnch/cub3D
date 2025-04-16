/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ema_blnch <ema_blnch@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:03:54 by eblancha          #+#    #+#             */
/*   Updated: 2025/03/11 14:13:43 by ema_blnch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

size_t	gnl_strlcpy(char *dest, const char *source, size_t dest_size)
{
	size_t	index;

	if (!source)
		return (0);
	if (dest_size == 0)
		return (ft_strlen((char *)source));
	index = 0;
	if (dest_size > 0)
	{
		while (source[index] && index < dest_size - 1)
		{
			dest[index] = source[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (ft_strlen((char *)source));
}
