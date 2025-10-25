/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:36 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/14 18:26:19 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_power(int n)
{
	unsigned int	nbr;
	int				power;

	power = 0;
	if (n <= 0)
	{
		power ++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		power ++;
		nbr /= 10;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*res;
	int				len_malloc;
	int				i;

	len_malloc = get_power(n);
	res = ft_calloc(len_malloc + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
		nbr = -n;
	}
	else
		nbr = n;
	while (len_malloc > i)
	{
		len_malloc --;
		res[len_malloc] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}
