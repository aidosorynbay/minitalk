/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:07:59 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/11 08:39:55 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_condition(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_char(args));
	else if (c == 's')
		return (ft_printf_str(args));
	else if (c == '%')
		return (ft_printf_percent(c));
	else if (c == 'd' || c == 'i')
		return (ft_printf_decimal(args));
	else if (c == 'u')
		return (ft_printf_unsigned(args));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hexa(args, c));
	else if (c == 'p')
		return (ft_printf_ptr(args));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;
	int		write_count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			write_count = write(1, &str[i], 1);
		else
			write_count = check_condition(str[++i], args);
		if (write_count == -1)
		{
			va_end(args);
			return (-1);
		}
		count += write_count;
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	unsigned long long d = 1844674407370955165;
// 	int a = printf("char: %c, string: %s, percent: %%, num_d: %d,
// 	num_u: %u, num_i: %i, hexa_l: %x, hexa_u: %X, ptr: %p\n", 't',
// 	NULL, 42, -1, 0x2b, 0x7fedcba1, -1, &d);
// 	int b = ft_printf("char: %c, string: %s, percent: %%, num_d: %d,
// 	num_u: %u, num_i: %i, hexa_l: %x, hexa_u: %X, ptr: %p\n",'t',
// 	NULL, 42, -1, 0x2b, 0x7fedcba1, -1, &d);
// 	printf("%d\n", a);
// 	printf("%d\n", b);
// }