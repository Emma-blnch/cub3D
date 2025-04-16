/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:10:40 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/09 15:10:51 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, char c)
{
	unsigned int	nbr;
	int				format_len;

	format_len = 0;
	if (c == 's')
		format_len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		format_len += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		format_len += ft_putchar(va_arg(args, int));
	else if (c == 'u')
		format_len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		format_len += ft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
	{
		nbr = va_arg(args, unsigned int);
		format_len += ft_put_hexa(nbr, c);
	}
	else if (c == '%')
		format_len += ft_putchar('%');
	return (format_len);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	index = 0;
	count = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			count += ft_check_format(args, format[index + 1]);
			index++;
		}
		else
			count += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (count);
}
