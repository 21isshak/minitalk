/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:20:21 by iskaraag          #+#    #+#             */
/*   Updated: 2024/06/25 11:20:22 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	short int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
	usleep(450);
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	char		*str;

	if (argc != 3)
	{
		ft_printf("ERROR\nUsage: ./client <PID> <Message>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("ERROR!!\nWRONG PID!!!");
		return (1);
	}
	str = argv[2];
	while (*str != '\0')
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
	return (0);
}
