/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:40 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:40 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "draw.h"
#include "libft.h"
#include "raycasting.h"
#include <math.h>

void	get_delta_dist(t_ray *ray)
{
	ray->delta.x = fabs(1 / ray->dir.x);
	ray->delta.y = fabs(1 / ray->dir.y);
}

void	get_first_dist(t_ray *ray, t_game game)
{
	if (ray->dir.x > 0)
	{
		ray->dist.x = ((int)game.player.pos.x + 1 - game.player.pos.x)
			* ray->delta.x;
		ray->step.x = +1;
	}
	else
	{
		ray->dist.x = (game.player.pos.x - (int)game.player.pos.x)
			* ray->delta.x;
		ray->step.x = -1;
	}
	if (ray->dir.y > 0)
	{
		ray->dist.y = ((int)game.player.pos.y + 1 - game.player.pos.y)
			* ray->delta.y;
		ray->step.y = +1;
	}
	else
	{
		ray->dist.y = (game.player.pos.y - (int)game.player.pos.y)
			* ray->delta.y;
		ray->step.y = -1;
	}
}

void	dda(t_data *data, t_ray *ray)
{
	t_coor	map_temp;
	t_game	game;

	game = data->game;
	get_delta_dist(ray);
	get_first_dist(ray, game);
	map_temp = set_coor((int)game.player.pos.x, (int)game.player.pos.y);
	while (true)
	{
		if (ray->dist.x < ray->dist.y)
		{
			ray->dist.x += ray->delta.x;
			map_temp.x += (int)ray->step.x;
			ray->texture = _E * ray->step.x;
		}
		else
		{
			ray->dist.y += ray->delta.y;
			map_temp.y += (int)ray->step.y;
			ray->texture = _S * ray->step.y;
		}
		if (game.map[map_temp.y][map_temp.x] == '1')
			return (ray_final_len(ray, data), draw_ray(*ray, data), (void)(0));
	}
}

void	send_rays(t_data *data)
{
	t_ray	ray;
	double	camera_x;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ft_memset(&ray, 0, sizeof(ray));
		ray.x = x;
		camera_x = 2 * (double)x / WIDTH - 1;
		ray.dir.x = data->game.player.dir.x + data->game.player.plan.x
			* camera_x;
		ray.dir.y = data->game.player.dir.y + data->game.player.plan.y
			* camera_x;
		dda(data, &ray);
		x++;
	}
}
