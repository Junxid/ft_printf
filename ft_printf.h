/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouil <itouil@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:18:41 by itouil            #+#    #+#             */
/*   Updated: 2023/10/02 16:19:00 by itouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(long n);
int	ft_puthex(unsigned long n, int upcase);
int	ft_putptr(void *ptr);
int	ft_format(const char format, va_list args);
int	ft_printf(const char *str, ...);

#endif
