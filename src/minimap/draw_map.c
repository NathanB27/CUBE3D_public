/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:11:29 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/23 18:34:07 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "draw.h"
#include <unistd.h>

static void	draw_tile_fill(t_data *data, t_vector start, t_vector end)
{
	t_vector	p;

	p.y = start.y;
	while (p.y < end.y)
	{
		p.x = start.x;
		while (p.x < end.x)
		{
			if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
				put_pixel(&data->i_game, (int)p.x, (int)p.y, 0xFFFFFF);
			p.x++;
		}
		p.y++;
	}
}

static void	draw_top_edge(t_data *data, t_vector start, t_vector end,
		t_coor coor)
{
	int	x;

	if (coor.y == 0 || data->game.map[coor.y - 1][coor.x] != '1')
	{
		x = (int)start.x;
		while (x < end.x)
		{
			if (x >= 0 && x < WIDTH)
				put_pixel(&data->i_game, x, (int)start.y, 0xFFFFFF);
			x++;
		}
	}
}

static void	draw_bottom_edge(t_data *data, t_vector start, t_vector end,
		t_coor coor)
{
	int	x;

	if (data->game.map[coor.y + 1] == NULL
		|| data->game.map[coor.y + 1][coor.x] != '1')
	{
		x = (int)start.x;
		while (x < end.x)
		{
			if (x >= 0 && x < WIDTH)
				put_pixel(&data->i_game, x, (int)end.y - 1, 0xFFFFFF);
			x++;
		}
	}
}

static void	draw_right_edge(t_data *data, t_vector start, t_vector end,
		t_coor coor)
{
	int	y;

	if (data->game.map[coor.y][coor.x + 1] == '\0'
		|| data->game.map[coor.y][coor.x + 1] != '1')
	{
		y = (int)start.y;
		while (y < end.y)
		{
			if (y >= 0 && y < HEIGHT)
				put_pixel(&data->i_game, (int)(end.x - 1), y, 0xFFFFFF);
			y++;
		}
	}
}

void	draw_tile_with_faces(t_data *data, t_coor coor, int tile_size)
{
	t_vector	start;
	t_vector	end;

	start.x = coor.x * tile_size;
	start.y = coor.y * tile_size;
	end.x = start.x + tile_size;
	end.y = start.y + tile_size;
	draw_tile_fill(data, start, end);
	draw_top_edge(data, start, end, coor);
	draw_bottom_edge(data, start, end, coor);
	draw_right_edge(data, start, end, coor);
}
