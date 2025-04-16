/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:10:35 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/14 13:17:40 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
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
	int		i;
	char	*result;
	long	nb;

	nb = n;
	size = size_total(nb);
	result = pre_conv(size);
	if (!result)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	i = size - 1;
	while (nb != 0)
	{
		result[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[size] = '\0';
	return (result);
}
