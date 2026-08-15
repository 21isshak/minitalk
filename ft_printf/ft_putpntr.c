/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpntr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:14:24 by iskaraag          #+#    #+#             */
/*   Updated: 2024/04/02 01:14:25 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(unsigned long c)
{
	int	a;

	a = 0;
	if (c / 16 != 0)
		a += ft_x(c / 16);
	a += ft_puthex(c % 16);
	return (a);
}

int	ft_putpntr(void *ptr)
{
	int	ahm;

	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ahm = 2;
	ft_putstr("0x");
	ahm += ft_x((unsigned long) ptr);
	return (ahm);
}
