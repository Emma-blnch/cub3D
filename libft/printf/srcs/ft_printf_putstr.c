/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:19 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/09 15:07:58 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *string)
{
	int	index;

	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	index = 0;
	while (string[index])
	{
		write(1, &string[index], 1);
		index++;
	}
	return (index);
}
