/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:20:29 by iskaraag          #+#    #+#             */
/*   Updated: 2024/06/25 11:20:31 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static int	karakter;
	static int	bit;

	if (sig == SIGUSR1)
		karakter |= (1 << bit);
	else
		karakter |= (0 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &karakter, 1);
		bit = 0;
		karakter = 0;
	}
}

int	main(void)
{
	ft_printf("PID:\t%d\n", getpid());
	ft_printf("Server waiting for client message...\n");
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		usleep(1);
}
/*
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

void	handle_signal(int sig)
{
	static int	karakter;
	static int	bit;

	if (sig == SIGUSR1)
	{
		karakter |= (1 << bit);
	}
	bit++;

	if (bit == 8)
	{
		printf("%c", karakter);
		fflush(stdout);
		bit = 0;
		karakter = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	(void)argv;
	if (argc != 1)
	{
		printf("ERROR\nUsage: ./server\n");
		return (1);
	}
	pid = getpid();
	printf("PID: %d\n", pid);
	printf("Server waiting for client message...\n");
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handle_signal;
	sa.sa_flags = SA_RESTART;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
//	onceki satirin devami sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (1);
	}

	while (1)
	{
		pause();
	}
	return (0);
}
*/
