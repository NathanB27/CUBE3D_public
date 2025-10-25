/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:25:37 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:25:37 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "struct.h"

int		calculate_tile_size(t_data *data);
void	draw_map(t_data *data);
void	draw_player_point(t_data *data, int player_x, int player_y);
void	draw_tile_with_faces(t_data *data, t_coor coor, int tile_size);

#endif
