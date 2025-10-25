/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:20 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:20 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parsing.h"
#include <fcntl.h>

int	set_visual(int fd, t_game_info *game_infos)
{
	char	*line;
	char	elements[6][2];
	int		total_elements;
	int		info;

	total_elements = 0;
	ft_memset(elements, 0, sizeof(elements));
	while (total_elements < 6)
	{
		line = gnl_no_nl(fd);
		info = check_line(line);
		if (info == color || info == texture)
		{
			if (info == color && set_color(&total_elements, elements, line,
					game_infos))
				return (free(line), 1);
			if (info == texture && !set_texture(&total_elements, elements, line,
					game_infos))
				return (free(line), 1);
		}
		else if (*line)
			return (free(line), 1);
		free(line);
	}
	return (!(total_elements == 6));
}

/**
 * @brief: create the tab for the map, resize it, check if the map is valide
 *
 * @param fd: where map is read
 * @param info_game: struct for map
 * @return 0 on succes
 */
int	parse_map(int fd, t_game_info *info_game)
{
	if (map_to_tab(fd, info_game))
		return (1);
	if (map_to_rec(info_game))
		return (1);
	if (check_map_validity(info_game->map, &(info_game->startdir),
			&(info_game->startpos)))
		return (1);
	return (0);
}

/**
 * @brief take a path to a file desc and parse it
 *
 * @param path path of the map  
 * @return the parse data on succes or exit prog
 */
t_game_info	parse(char *path)
{
	t_game_info	game_info;
	int			fd;

	fd = -1;
	ft_memset(&game_info, 0, sizeof(game_info));
	if (check_extension(path, EXT_MAPDESC))
		exit_parsing("invalid extension", game_info, fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_parsing("error opening file", game_info, fd);
	if (set_visual(fd, &game_info))
		exit_parsing("error visual description is not valid", game_info, fd);
	if (parse_map(fd, &game_info))
		exit_parsing("error map is not valid", game_info, fd);
	close(fd);
	return (game_info);
}
