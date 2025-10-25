/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:40:29 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/11 13:19:48 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_len_num(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len -1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	num = 0;
	if (n == 0)
		length += write (1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		length += ft_printstr(num);
		free (num);
	}
	return (length);
}

int	ft_len_num(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
