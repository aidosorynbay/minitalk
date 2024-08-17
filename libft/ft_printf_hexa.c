/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:35:46 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/11 08:39:06 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_zero(char *hex)
{
	int	write_count;

	write_count = write(1, &hex[0], 1);
	if (write_count == -1)
		return (-1);
	return (1);
}

static int	ft_puthexa(unsigned int n, char c, int i)
{
	char	*hex;
	char	buffer[9];
	int		count;
	int		write_count;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n == 0)
		return (ft_zero(hex));
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	count = i;
	while (i > 0)
	{
		write_count = write(1, &buffer[--i], 1);
		if (write_count == -1)
			return (-1);
	}
	return (count);
}

int	ft_printf_hexa(va_list args, char c)
{
	int				count;
	unsigned int	n;
	int				i;

	i = 0;
	n = va_arg(args, unsigned int);
	count = ft_puthexa(n, c, i);
	return (count);
}
