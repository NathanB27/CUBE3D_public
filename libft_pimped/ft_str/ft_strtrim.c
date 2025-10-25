/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:44:33 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/15 16:30:33 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char	const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && is_in_set(set, s1[i]))
		i++;
	while (len > i && is_in_set(set, s1[len - 1]))
		len--;
	dest = (char *)ft_calloc(len - i + 1, sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1 + i, len - i);
	return (dest);
}
