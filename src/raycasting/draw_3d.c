/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:46 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:46 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "draw.h"
#include "struct.h"

int	rgb_to_int(t_color rgb)
{
	return ((int)(rgb.b) + ((int)(rgb.g) << 8) + ((int)(rgb.r) << 16));
}

void	draw_floor_celling(t_ray ray, t_data *data, double start, double end)
{
	double	floor;

	floor = (double)HEIGHT - 1.0;
	while (end >= 0)
	{
		put_pixel(&data->i_game, ray.x, (int)end, data->colors[1]);
		end--;
	}
	while (floor > start)
	{
		put_pixel(&data->i_game, ray.x, (int)floor, data->colors[0]);
		floor--;
	}
}

t_img	get_current_texture(float id, t_data data)
{
	t_img	img;

	if (id == _N)
		img = data.textures[0];
	if (id == _S)
		img = data.textures[1];
	if (id == _E)
		img = data.textures[2];
	if (id == _W)
		img = data.textures[3];
	return (img);
}

void	draw_ray(t_ray ray, t_data *data)
{
	double	ray_height;
	t_point	len;
	t_img	img;
	double	y;

	ray_height = (double)HEIGHT / ray.final_dist;
	len.x = (double)HEIGHT / 2.0 - ray_height / 2.0;
	len.y = (double)HEIGHT / 2.0 + ray_height / 2.0;
	if (len.y >= (double)HEIGHT)
		len.y = (double)HEIGHT - 1;
	img = get_current_texture(ray.texture, *data);
	y = 0;
	if (len.x < 0)
	{
		y = ((double)img.size.y / (double)ray_height) * -len.x;
		len.x = 0;
	}
	draw_floor_celling(ray, data, (int)len.x, (int)len.y);
	while (len.x <= len.y)
	{
		put_pixel(&data->i_game, ray.x, (int)len.x, get_pixel(&img,
				(int)(ray.x_texture * img.size.x), (int)y));
		y += (double)img.size.y / (double)ray_height;
		len.x++;
	}
}
