/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:09:53 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/14 15:07:07 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	int		size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= (unsigned int)size)
		return (ft_strdup(""));
	if ((size - start) < len)
		len = size - start;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
