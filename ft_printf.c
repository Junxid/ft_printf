/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouil <itouil@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:16:37 by itouil            #+#    #+#             */
/*   Updated: 2023/10/02 16:42:03 by itouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format == 'X'));
	if (format == '%')
		return (ft_putchar('%'));
	return (ft_putchar(format));
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			len += ft_format(*(++str), args);
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
