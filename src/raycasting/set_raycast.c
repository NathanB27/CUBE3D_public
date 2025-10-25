/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:43:37 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:43:37 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "minimap.h"
#include "mlx.h"
#include "raycasting.h"
#include <math.h>

void	set_vectors(t_game *game, t_game_info parsing_data)
{
	if (parsing_data.startdir == N)
		game->player.dir = init_vector(0, -1);
	if (parsing_data.startdir == S)
		game->player.dir = init_vector(0, 1);
	if (parsing_data.startdir == E)
		game->player.dir = init_vector(1, 0);
	else if (parsing_data.startdir == W)
		game->player.dir = init_vector(-1, 0);
	game->player.plan.x = -(game->player.dir.y) * tan(deg_to_rad(FOV) / 2);
	game->player.plan.y = game->player.dir.x * tan(deg_to_rad(FOV) / 2);
}

t_data	set_data(t_game_info parsing_data)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.game.player.pos.x = parsing_data.startpos.x + 0.5;
	data.game.player.pos.y = parsing_data.startpos.y + 0.5;
	data.game.map = parsing_data.map;
	data.colors[0] = rgb_to_int(parsing_data.spirits.f);
	data.colors[1] = rgb_to_int(parsing_data.spirits.c);
	set_vectors(&data.game, parsing_data);
	data.display_map = 1;
	return (data);
}

void	start_game(t_game_info parsing_data)
{
	t_data	data;

	data = set_data(parsing_data);
	init_mlx(&data, parsing_data);
	send_rays(&data);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx, data.window, data.i_game.img, 0, 0);
	mlx_loop(data.mlx);
}
