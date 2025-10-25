/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:30:35 by nboucher          #+#    #+#             */
/*   Updated: 2025/02/17 16:22:00 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	taille_dst;
	unsigned int	taille_src;
	unsigned int	i;
	unsigned int	j;

	taille_dst = ft_strlen(dst);
	taille_src = ft_strlen(src);
	i = 0;
	j = taille_dst;
	if (size <= taille_dst)
		return (taille_src + size);
	while (i < size -1 - taille_dst && src[i])
	{	
		dst[j] = src[i];
		j ++;
		i ++;
	}
	dst[j] = '\0';
	return (taille_dst + taille_src);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i ++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}
