/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:07 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:07 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parsing.h"

/**
 * @brief check if wall is valid: no wall no connect to the rest of the map
 *
 * @param map : map
 * @param x : current x in the map
 * @param y : current y in the map
 * @return : if wall is valid
 */
int	wall_valid(char **map, int x, int y)
{
	static int	len_x;
	static int	len_y;

	len_x = (int)ft_strlen(map[0]) - 1;
	len_y = tab_string_len_y(map) - 1;
	if (x != len_x && map[y][x + 1] != MAP_VOID)
		return (0);
	if (x != 0 && map[y][x - 1] != MAP_VOID)
		return (0);
	if (x != 0 && y != len_y && map[y + 1][x - 1] != MAP_VOID)
		return (0);
	if (y != len_y && map[y + 1][x] != MAP_VOID)
		return (0);
	if (y != len_y && x != len_x && map[y + 1][x + 1] != MAP_VOID)
		return (0);
	if (y != 0 && x != 0 && map[y - 1][x - 1] != MAP_VOID)
		return (0);
	if (y != 0 && map[y - 1][x] != MAP_VOID)
		return (0);
	if (y != 0 && x != len_x && map[y - 1][x + 1] != MAP_VOID)
		return (0);
	return (1);
}

/**
 * @brief check if a floor is valid (valid floor: not connected to void)
 *
 * @param map : map  
 * @param x : current x
 * @param y : current y
 * @return 0 on succes
 */
int	floor_valid(char **map, int x, int y)
{
	static int	len_x;
	static int	len_y;

	len_x = (int)ft_strlen(map[0]);
	len_y = tab_string_len_y(map);
	if (x == 0 || x == len_x - 1 || y == 0 || y == len_y - 1)
		return (1);
	if (map[y][x + 1] == MAP_VOID)
		return (1);
	if (map[y][x - 1] == MAP_VOID)
		return (1);
	if (map[y + 1][x] == MAP_VOID)
		return (1);
	if (map[y - 1][x] == MAP_VOID)
		return (1);
	return (0);
}

// check map validity, surrounded, one start pos
/**
 * @brief check if map is valid: surrounded, on start pos
 *
 * @param map 
 * @param start_dir : adress of start dir of the player
 * @param start_pos : x and y of the player start position
 * @return 0 on succes
 */
int	check_map_validity(char **map, char *start_dir, t_point *start_pos)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (is_charset(map[y][x], MAP_CHARSET_NO_SPACE))
			{
				if ((is_charset(map[y][x], MAP_FLOOR) && floor_valid(map, x, y))
					|| (map[y][x] == MAP_WALL && wall_valid(map, x, y)))
					return (1);
				if (is_charset(map[y][x], MAP_PLAYER))
				{
					if (*start_dir)
						return (1);
					*start_dir = map[y][x];
					set_t_point(x, y, start_pos);
				}
			}
		}
	}
	return (!(*start_dir));
}
