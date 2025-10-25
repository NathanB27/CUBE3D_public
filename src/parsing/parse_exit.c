/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:18 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:18 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

void	free_path_textures(t_game_info parsing)
{
	if (parsing.spirits.ea)
		free(parsing.spirits.ea);
	if (parsing.spirits.we)
		free(parsing.spirits.we);
	if (parsing.spirits.so)
		free(parsing.spirits.so);
	if (parsing.spirits.no)
		free(parsing.spirits.no);
}

/**
 * @brief exit prog and free all the parsing struct t_gameInfo
 *
 * @param message print at the exit on stderror
 * @param game_info struct free
 */
void	exit_parsing(char *message, t_game_info game_info, int fd)
{
	if (fd != -1)
		close(fd);
	if (game_info.map)
		ft_free_all(game_info.map);
	free_path_textures(game_info);
	ft_putstr_fd("Error\n", 2);
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(1);
}
