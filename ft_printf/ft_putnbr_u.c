/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:33:27 by iskaraag          #+#    #+#             */
/*   Updated: 2024/04/05 01:33:29 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	ahm;

	ahm = 0;
	if (nb > 9)
		ahm += ft_putnbr_u(nb / 10);
	ahm += ft_putchar(nb % 10 + '0');
	return (ahm);
}
