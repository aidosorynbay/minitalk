/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:03:17 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/20 13:34:38 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int	pid;
	
	pid = getpid();
	ft_printf("Client PID: %d\n", pid);
	if (argc != 3)
	{
		write(2, "Invalid input\n", 15);
		return (0);
	}
	send_action(ft_atoi(argv[1]), argv[2]);
	return (0);
}
