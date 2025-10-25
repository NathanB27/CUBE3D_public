/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:26 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:26 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parsing.h"

// to do check if spirit exist i mean the file,
// check if the dimesion are good (different path but same texture??)

/**
 * @brief set path for the texture after all check (no doublon, valid path)
 *
 * @param total_elements ids already traited
 * @param elements nb of ids already traited
 * @param line current line with the texture
 * @param game_info struct filled with the path
 * @return a valid ptr on succes
 */
char	*set_texture(int *total_elements, char elements[6][2], char *line,
		t_game_info *game_info)
{
	char	*path;

	if (check_doublon(total_elements, elements, line))
		return (NULL);
	path = ft_strcdup(skip_space(skip_space(line) + 2), ' ');
	if (!path)
		return (NULL);
	if (ft_strncmp(line, SO, 3) == 0)
		game_info->spirits.so = path;
	else if (ft_strncmp(line, NO, 3) == 0)
		game_info->spirits.no = path;
	else if (ft_strncmp(line, EA, 3) == 0)
		game_info->spirits.ea = path;
	else if (ft_strncmp(line, WE, 3) == 0)
		game_info->spirits.we = path;
	return (path);
}

//gerer les return int void etc (plus propre)
