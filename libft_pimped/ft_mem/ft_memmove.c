/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:18:49 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/14 14:43:51 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst_cpy > src_cpy)
	{
		while (size > 0)
		{
			size --;
			dst_cpy[size] = src_cpy[size];
		}
		return (dst);
	}
	i = 0;
	while (i < size)
	{
		dst_cpy[i] = src_cpy[i];
		i ++;
	}
	return (dst);
}
