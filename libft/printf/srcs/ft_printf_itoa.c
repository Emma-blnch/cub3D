/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:10:35 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/09 15:08:45 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*allocation_and_initilization(int len)
{
	char	*result;

	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '0';
	return (result);
}

static int	size_total(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	size;
	int		index;
	char	*result;
	long	number;

	number = n;
	size = size_total(number);
	result = allocation_and_initilization(size);
	if (!result)
		return (NULL);
	if (number < 0)
		number = -number;
	index = size - 1;
	while (number != 0)
	{
		result[index] = (number % 10) + '0';
		number /= 10;
		index--;
	}
	if (n < 0)
		result[0] = '-';
	result[size] = '\0';
	return (result);
}
