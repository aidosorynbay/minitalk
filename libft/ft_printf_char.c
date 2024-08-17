/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:30:23 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/11 07:59:25 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list args)
{
	char	c;
	int		write_count;

	c = va_arg(args, int);
	write_count = write(1, &c, 1);
	if (write_count == -1)
		return (-1);
	return (1);
}
