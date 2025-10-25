/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:48:05 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/24 10:02:28 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "draw.h"
#include "minimap.h"

int	calculate_tile_size(t_data *data)
{
	int	rows;
	int	cols;
	int	tile_width;
	int	tile_height;

	rows = 0;
	cols = 0;
	while (data->game.map[rows])
		rows++;
	while (data->game.map[0][cols])
		cols++;
	tile_width = (WIDTH / 5) / cols;
	tile_height = (HEIGHT / 5) / rows;
	if (tile_width > tile_height)
		data->tile_size = tile_height;
	else
		data->tile_size = tile_width;
	return (data->tile_size);
}

void	draw_player_point(t_data *data, int player_x, int player_y)
{
	int	x;
	int	y;
	int	radius;

	radius = 4;
	y = player_y - radius;
	while (y <= player_y + radius)
	{
		x = player_x - radius;
		while (x <= player_x + radius)
		{
			if ((x - player_x) * (x - player_x) + (y - player_y) * (y
					- player_y) <= radius * radius)
			{
				if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
					put_pixel(&data->i_game, x, y, 0xFFF00);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data)
{
	t_coor	coor;
	int		tile_size;

	tile_size = calculate_tile_size(data);
	coor.y = 0;
	draw_player_point(data, data->game.player.pos.x * tile_size,
		data->game.player.pos.y * tile_size);
	while (data->game.map[coor.y])
	{
		coor.x = 0;
		while (data->game.map[coor.y][coor.x])
		{
			if (data->game.map[coor.y][coor.x] == '1')
				draw_tile_with_faces(data, coor, tile_size);
			coor.x++;
		}
		coor.y++;
	}
}
