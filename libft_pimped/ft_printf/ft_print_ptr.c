/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:05:39 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/11 13:19:25 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptr_len(unsigned long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long int num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + 48);
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	if (!ptr)
	{
		length += write (1, "(nil)", 5);
		return (length);
	}
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write (1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}
