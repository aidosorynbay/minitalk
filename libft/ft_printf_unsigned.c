/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:33:46 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/11 08:39:31 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_u(unsigned int n)
{
	char	c;
	int		count;
	int		write_count;

	c = '\0';
	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	if (count == -1)
		return (-1);
	c = n % 10 + '0';
	write_count = write(1, &c, 1);
	if (write_count == -1)
		return (-1);
	return (count + write_count);
}

int	ft_printf_unsigned(va_list args)
{
	unsigned int	n;
	int				count;

	n = va_arg(args, unsigned int);
	count = ft_putnbr_u(n);
	return (count);
}
