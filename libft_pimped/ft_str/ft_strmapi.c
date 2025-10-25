/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:35:19 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/14 18:46:15 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*result;
	int		i;

	len = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len ++;
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i ++;
	}	
	result[len] = '\0';
	return (result);
}
