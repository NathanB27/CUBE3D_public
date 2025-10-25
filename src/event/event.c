/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:00:07 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:00:07 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "define.h"
#include "minimap.h"
#include "mlx.h"
#include "movement.h"
#include "raycasting.h"

void	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		return (exit_prog(data), (void)data);
	mlx_destroy_image(data->mlx, data->i_game.img);
	data->i_game.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->i_game.img)
		exit_failure(data);
	if (keycode == KEY_A)
		translate_pos_left_right(data, LEFT);
	else if (keycode == KEY_D)
		translate_pos_left_right(data, RIGHT);
	else if (keycode == KEY_P)
		data->display_map = !data->display_map;
	else if (keycode == KEY_W)
		translate_pos_up_down(data, UP);
	else if (keycode == KEY_S)
		translate_pos_up_down(data, DOWN);
	else if (keycode == KEY_LEFT)
		rotate_dir(data, -1);
	else if (keycode == KEY_RIGHT)
		rotate_dir(data, 1);
	send_rays(data);
	mlx_clear_window(data->mlx, data->window);
	if (data->display_map == 1)
		draw_map(data);
	mlx_put_image_to_window(data->mlx, data->window, data->i_game.img, 0, 0);
}
