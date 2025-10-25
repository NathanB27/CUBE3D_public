/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:42 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:42 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "struct.h"
#include <math.h>

double	deg_to_rad(double angle)
{
	return (angle * (M_PI / 180.0));
}

t_vector	init_vector(double x, double y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	return (v);
}

void	ray_final_len(t_ray *ray, t_data *data)
{
	int	one;

	one = 0;
	if (ray->texture == _S || ray->texture == _W)
		one = 1;
	if (ray->texture == _N || ray->texture == _S)
	{
		ray->final_dist = ray->dist.y - ray->delta.y;
		ray->x_texture = data->game.player.pos.x + ray->final_dist * ray->dir.x;
	}
	else
	{
		ray->final_dist = ray->dist.x - ray->delta.x;
		ray->x_texture = data->game.player.pos.y + ray->final_dist * ray->dir.y;
	}
	ray->x_texture -= (int)ray->x_texture;
	if (one)
		ray->x_texture = 1 - (ray->x_texture - (int)ray->x_texture);
}

t_coor	set_coor(int x, int y)
{
	t_coor	coor;

	coor.x = x;
	coor.y = y;
	return (coor);
}
