/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:23:59 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:23:59 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

void	put_pixel(t_img *img, int x, int y, int color);
void	draw_ray(t_ray ray, t_data *data);
int		get_pixel(t_img *img, int x, int y);

#endif // !DRAW_H
