/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tle-Prig <tom.leprigent@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:44:46 by Tle-Prig          #+#    #+#             */
/*   Updated: 2025/05/26 17:00:12 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "define.h"
#include "event.h"
#include "mlx.h"
#include <stdlib.h>

void	new_img(t_data *data, t_img *img, int x, int y)
{
	img->img = mlx_new_image(data->mlx, x, y);
	if (!img->img)
		exit_failure(data);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		exit_failure(data);
}

void	xpm_to_img(t_data *data, t_img *img, char *path, t_game_info parsing)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->size.x,
			&img->size.y);
	if (!img->img)
		return (free_path_textures(parsing), exit_failure(data));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (free_path_textures(parsing), exit_failure(data));
	free(path);
}

void	init_mlx(t_data *data, t_game_info parsing)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_path_textures(parsing), exit_failure(data));
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "game");
	if (!data->window)
		return (free_path_textures(parsing), exit_failure(data));
	xpm_to_img(data, &data->textures[0], parsing.spirits.no, parsing);
	parsing.spirits.no = NULL;
	xpm_to_img(data, &data->textures[1], parsing.spirits.so, parsing);
	parsing.spirits.so = NULL;
	xpm_to_img(data, &data->textures[2], parsing.spirits.ea, parsing);
	parsing.spirits.ea = NULL;
	xpm_to_img(data, &data->textures[3], parsing.spirits.we, parsing);
	parsing.spirits.we = NULL;
	new_img(data, &data->i_game, WIDTH, HEIGHT);
	mlx_hook(data->window, 2, 1L << 0, *handle_keypress, data);
	mlx_hook(data->window, 17, 1L << 17, exit_prog, data);
}
