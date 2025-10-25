/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:49:11 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/22 13:48:52 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	result;

	result = 0;
	signe = 1;
	i = 0;
	while (white_space(str[i]))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
	}
	return (signe * result);
}

long int	ft_atoli(const char *str)
{
	int			i;
	int			signe;
	long int	result;

	result = 0;
	signe = 1;
	i = 0;
	while (white_space(str[i]))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
	}
	return (signe * result);
}

bool	is_long_int(const char *str)
{
	long int	nb;

	nb = ft_atoli(str);
	if ((nb > 2147483647) || (nb < -2147483648))
		return (true);
	else
	{
		return (false);
	}
}
