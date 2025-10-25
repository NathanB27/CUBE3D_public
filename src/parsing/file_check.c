/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:43:09 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:43:09 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check the extension on a file
 *
 * @param path file path
 * @param extension extension checked
 * @return 0 on succes
 */
int	check_extension(char *path, char *extension)
{
	size_t	len;

	if (!path || !extension)
		return (1);
	len = ft_strlen(path);
	if (ft_strlen(extension) >= len)
		return (1);
	if (len <= 4 || strcmp(&path[len - (int)(ft_strlen(extension))],
		extension) != 0)
		return (1);
	return (0);
}
