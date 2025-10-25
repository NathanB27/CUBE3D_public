/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:12:18 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/15 15:50:25 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[j])
	{
		i = 0;
		while (str[i + j] && to_find[i] == str[i + j] && i + j < len)
			i++;
		if (!to_find[i])
			return ((char *)str + j);
		j++;
	}
	return (0);
}
