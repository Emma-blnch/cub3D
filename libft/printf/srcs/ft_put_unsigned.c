/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:29 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/09 15:09:34 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	unsigned_count_digits(unsigned int number)
{
	size_t	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

static void	write_unsigned(unsigned int number)
{
	if (number >= 10)
		write_unsigned(number / 10);
	ft_putchar((number % 10) + '0');
}

int	ft_put_unsigned(unsigned int number)
{
	if (number == 0)
	{
		ft_putchar('0');
		return (1);
	}
	write_unsigned(number);
	return (unsigned_count_digits(number));
}
