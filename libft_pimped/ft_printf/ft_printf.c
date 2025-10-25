/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:14:44 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/11 13:19:32 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_scan(const char c, va_list args)
{
	int	length;

	length = 0;
	if (c == '%')
		length += ft_print_percent();
	if (c == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), c);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_scan(str[i + 1], args);
			i++;
		}
		else
			len += write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
