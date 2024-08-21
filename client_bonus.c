/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:36:20 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/20 13:36:20 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_exit_sign = 0;

void	acknow_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("The string was received by the server.\n");
		g_exit_sign = 1;
	}
}

void	send_action(int pid, char *str)
{
	int	c;
	int	count;
	int	len;
	int	i;

	len = ft_strlen(str);
	len++;
	i = 0;
	while (i < len)
	{
		count = 7;
		c = *str;
		while (count >= 0)
		{
			if (((c >> count) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			count--;
			usleep(1000);
		}
		str++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "Invalid input\n", 15);
		return (0);
	}
	signal(SIGUSR1, acknow_handler);
	send_action(ft_atoi(argv[1]), argv[2]);
	if (g_exit_sign == 1)
		return (0);
	else
		pause();
}
