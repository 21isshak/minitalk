/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:11:04 by iskaraag          #+#    #+#             */
/*   Updated: 2024/04/02 01:11:06 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list args)
{
	int	ahm;

	ahm = 0;
	if (*format == 'c')
		ahm += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		ahm += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		ahm += ft_putpntr(va_arg(args, void *));
	else if (*format == 'd')
		ahm += ft_putnbr(va_arg(args, int));
	else if (*format == 'i')
		ahm += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		ahm += ft_putnbr_u(va_arg(args, unsigned int));
	if (*format == 'x')
		ahm += ft_puthex(va_arg(args, unsigned int));
	else if (*format == 'X')
		ahm += ft_puthex_up(va_arg(args, unsigned int));
	else if (*format == '%')
		ahm += ft_putchar('%');
	return (ahm);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ahm;

	ahm = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
			ahm += ft_putchar(*format);
		else
		{
			format++;
			ahm += ft_format(format, args);
		}
		format++;
	}
	va_end(args);
	return (ahm);
}
