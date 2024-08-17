/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:08:03 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/21 16:31:13 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf_char(va_list args);
int	ft_printf_decimal(va_list args);
int	ft_printf_hexa(va_list args, char c);
int	ft_printf_percent(char c);
int	ft_printf_ptr(va_list args);
int	ft_printf_str(va_list args);
int	ft_printf_unsigned(va_list args);
int	ft_printf(const char *str, ...);

#endif