/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:21:03 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/27 11:21:03 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

/**
	* @brief recreate the thamp adding space at the end of lines in
	* order that allines have the same lenght
 *
 * @param info_game [map]
 * @return 0 on succes
 */
int	map_to_rec(t_game_info *info_game)
{
	int		y;
	int		max_x;
	char	*temp;

	max_x = tab_string_max_len(info_game->map);
	y = 0;
	while (info_game->map[y])
	{
		if ((int)ft_strlen(info_game->map[y]) < max_x)
		{
			temp = ft_calloc(max_x + 1, sizeof(char));
			if (!temp)
				return (1);
			ft_memset(temp, ' ', (int)max_x);
			ft_memcpy(temp, info_game->map[y], ft_strlen(info_game->map[y]));
			free(info_game->map[y]);
			info_game->map[y] = temp;
		}
		y++;
	}
	return (0);
}

/**
 * @brief realloc tab and add new valid to the tab
 *
 * @param line line added to the tab
 * @param old_map tab where you adding the line
 * @return pointer to the new map on success
 */
char	**add_line_to_maptab(char *line, char **old_map)
{
	char	**new_map;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (old_map && old_map[i++])
		size++;
	new_map = (char **)ft_calloc(size + 2, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (old_map && old_map[i])
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i] = line;
	new_map[++i] = NULL;
	if (old_map)
		free((void *)old_map);
	return (new_map);
}

// free?
/**
 * @brief create map tap as line as line are valid for map
 *
 * @param fd file descriptor where lines are read
 * @param info_game stuct containing map
 * @return 0 on succes
 */
int	map_to_tab(int fd, t_game_info *info_game)
{
	char	*line;

	info_game->map = NULL;
	line = gnl_no_nl(fd);
	while (line && (!(*line) || is_space(line) == 0))
	{
		free(line);
		line = gnl_no_nl(fd);
	}
	while (line)
	{
		if (map_line_is_ok(line))
			return (free(line), 1);
		if (is_space(line) == 0 && info_game->map)
			return (check_end_map(fd, line));
		info_game->map = add_line_to_maptab(line, info_game->map);
		if (!info_game->map)
			return (1);
		line = gnl_no_nl(fd);
	}
	return (!info_game->map);
}
