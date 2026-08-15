/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:12:20 by iskaraag          #+#    #+#             */
/*   Updated: 2024/04/02 01:12:21 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	ahm;

	ahm = 0;
	if (nb == -2147483648)
		ahm = ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ahm += ft_putchar('-');
		}
		if (nb > 9)
		{
			ahm += ft_putnbr(nb / 10);
		}
		ahm += ft_putchar(nb % 10 + '0');
	}
	return (ahm);
}
