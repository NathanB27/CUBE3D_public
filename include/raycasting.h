/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:33:35 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:33:35 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

t_data		set_data(t_game_info parsing_data);
t_vector	init_vector(double x, double y);
t_coor		set_coor(int x, int y);
void		ray_final_len(t_ray *ray, t_data *data);
void		send_rays(t_data *data);
double		deg_to_rad(double angle);
int			rgb_to_int(t_color rgb);
void		init_mlx(t_data *data, t_game_info parsing);

#endif // !RAYCASTING_H
