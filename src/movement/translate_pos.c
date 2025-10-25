/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:27:12 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 17:27:12 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "movement.h"

void	translate_pos_left_right(t_data *data, int side)
{
	t_vector	player_perp;
	t_point		pos;
	double		step;

	player_perp.x = data->game.player.dir.y;
	player_perp.y = -data->game.player.dir.x;
	step = TRANSLATE_SPEED;
	if (side == RIGHT)
		step = -TRANSLATE_SPEED;
	pos.x = data->game.player.pos.x;
	pos.y = data->game.player.pos.y;
	if (data->game.map[(int)(pos.y + player_perp.y * step)][(int)pos.x] != '1')
		data->game.player.pos.y += player_perp.y * step;
	if (data->game.map[(int)pos.y][(int)(pos.x + player_perp.x * step)] != '1')
		data->game.player.pos.x += player_perp.x * step;
}

void	translate_pos_up_down(t_data *data, int side)
{
	t_vector	dir;
	t_point		pos;
	double		step;

	dir.x = data->game.player.dir.x;
	dir.y = data->game.player.dir.y;
	step = TRANSLATE_SPEED;
	if (side == DOWN)
		step = -TRANSLATE_SPEED;
	pos.x = data->game.player.pos.x;
	pos.y = data->game.player.pos.y;
	if (data->game.map[(int)(pos.y + dir.y * step)][(int)pos.x] != '1')
		data->game.player.pos.y += dir.y * step;
	if (data->game.map[(int)pos.y][(int)(pos.x + dir.x * step)] != '1')
		data->game.player.pos.x += dir.x * step;
}
