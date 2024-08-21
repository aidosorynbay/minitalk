/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:36:16 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/20 13:36:16 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << (7 - i));
	else if (signum == SIGUSR2)
		c &= ~(1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", c);
		fflush(stdout);
		c = '\0';
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
