/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putheX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:12:44 by iskaraag          #+#    #+#             */
/*   Updated: 2024/04/02 01:12:45 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up(unsigned int num)
{
	int	ahm;

	ahm = 0;
	if (num >= 16)
	{
		ahm += ft_puthex_up(num / 16);
		ahm += ft_puthex_up(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'A');
		ahm++;
	}
	return (ahm);
}
