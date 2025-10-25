/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:27:27 by nboucher          #+#    #+#             */
/*   Updated: 2025/04/18 11:52:19 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c != '\0')
	{
		if (c >= 'a' && c <= 'z')
		{
			return (1);
		}
		else if (c >= 'A' && c <= 'Z')
		{
			return (1);
		}
	}
	return (0);
}

int	ft_args_is_token(char *str)
{
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, "<"))
		return (0);
	if (!ft_strcmp(str, ">>") || !ft_strcmp(str, ">"))
		return (0);
	if (!ft_strcmp(str, "||") || !ft_strcmp(str, "|"))
		return (0);
	if (!ft_strcmp(str, "&&") || !ft_strcmp(str, "&"))
		return (0);
	if (!ft_strcmp(str, "<>") || !ft_strcmp(str, "><"))
		return (0);
	return (1);
}
