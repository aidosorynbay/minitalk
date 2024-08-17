/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:33:00 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/11 08:38:55 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max_neg(void)
{
	int	write_count;

	write_count = write(1, "-2147483648", 11);
	if (write_count == -1)
		return (-1);
	return (11);
}

static int	ft_neg(int *n)
{
	int	write_count;

	write_count = write(1, "-", 1);
	if (write_count == -1)
		return (-1);
	*n = -*n;
	return (1);
}

static int	ft_putnbr_d(int n)
{
	char	c;
	int		count;
	int		write_count;

	c = '\0';
	count = 0;
	if (n == -2147483648)
		return (ft_max_neg());
	else if (n < 0)
	{
		write_count = ft_neg(&n);
		if (write_count == -1)
			return (-1);
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_d(n / 10);
	if (count == -1)
		return (-1);
	c = n % 10 + '0';
	write_count = write(1, &c, 1);
	if (write_count == -1)
		return (-1);
	return (count + write_count);
}

int	ft_printf_decimal(va_list args)
{
	int		n;
	int		count;

	n = va_arg(args, int);
	count = ft_putnbr_d(n);
	return (count);
}
