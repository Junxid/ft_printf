/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouil <itouil@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:09 by itouil            #+#    #+#             */
/*   Updated: 2023/10/02 16:27:02 by itouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}

int	ft_putnbr(long n)
{
	int	len;

	len = 0;
	if (n > 9 || n < -9)
		len += ft_putnbr(n / 10);
	else if (n < 0)
		len += ft_putchar('-');
	len += ft_putchar('0' + n % 10 * ((n > 0) - (n < 0)));
	return (len);
}

int	ft_puthex(unsigned long n, int upcase)
{
	int		len;
	char	*base;

	len = 0;
	if (n > 15)
		len += ft_puthex(n / 16, upcase);
	base = "0123456789abcdef";
	len += ft_putchar(base[n % 16] + upcase * (('A' - 'a') * (n % 16 > 9)));
	return (len);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthex((unsigned long)ptr, 0));
}
