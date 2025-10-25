/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:11:36 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/07 14:06:03 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i ++;
	return (i);
}

size_t	count_words(char const *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

void	ft_free_all(char **res)
{
	int	j;

	j = 0;
	if (!res)
		return ;
	while (res[j])
		free(res[j++]);
	free(res);
}

char	*calloc_words(char const *s, char c)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = ft_calloc(ft_len(s, c) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**dest;

	dest = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!dest || !s)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			dest[j] = calloc_words(s, c);
			if (!dest[j])
			{
				ft_free_all(dest);
				return (NULL);
			}
			s += ft_len(s, c);
			j++;
		}
	}
	dest[j] = 0;
	return (dest);
}
