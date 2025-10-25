/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:56:52 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/14 14:56:59 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*mem;

	mem = (const char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char )mem[i] == (unsigned char)c)
			return ((void *)&mem[i]);
		i ++;
	}
	return (NULL);
}
