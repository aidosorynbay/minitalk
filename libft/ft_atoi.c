/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:36:24 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/19 11:57:45 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if (result > 2147483647U + (sign == -1))
			return (-1);
		str++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// char str[] = "9223372036854775806";
// 	char str[] = "2147483647";
// 	int one = 1;
// 	printf("{%i}\n", atoi(str));
// 	printf("{%i}\n", ft_atoi(str, &one));
// }
