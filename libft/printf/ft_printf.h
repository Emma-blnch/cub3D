/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:12:26 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/22 11:07:24 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define PRINTF_VALID_FORMATS "cspdiuxX\%"

int		ft_printf(const char *format, ...);
int		ft_putptr(void *pointer);
int		ft_put_hexa(unsigned int number, const char format);
int		ft_put_unsigned(unsigned int number);
int		ft_putchar(char character);
int		ft_putnbr(int n);
int		ft_putstr(char *string);
size_t	ft_strlen(const char *string);
char	*ft_itoa(int n);

#endif
