/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_splitable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:25:55 by nboucher          #+#    #+#             */
/*   Updated: 2025/02/15 18:48:08 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_is_splitable(char *arg)
{
	int	i;
	int	is_splitable;

	i = 0;
	is_splitable = 0;
	if (arg == NULL || *arg == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] != ' ')
		{
			is_splitable = 1;
			break ;
		}
		i++;
	}
	return (is_splitable);
}
