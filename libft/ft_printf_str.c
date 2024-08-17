/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:31:19 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/11 07:59:47 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(va_list args)
{
	char	*str;
	int		i;
	int		write_count;

	i = 0;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		write_count = write(1, "(null)", 6);
		if (write_count == -1)
			return (-1);
		return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			write_count = write(1, &str[i], 1);
			if (write_count == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}
