/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:03:13 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/19 17:35:51 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_message_received;

int	g_client_pid;

void	signal_handler(int signum)
{
	static int	i = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c |= (1 << (7 - i));
	else if (signum == SIGUSR2)
		c &= ~(1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (c == '\0')
			g_message_received = 1;
		else
			ft_printf("%c", c);
		c = '\0';
		i = 0;
	}
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	g_client_pid = 0;
	g_message_received = 0;
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
